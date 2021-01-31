function lab_25(r::Robot)
    go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)
    my_ans = go_inside_rect_and_return_median_t!(r, West)
    border_now = false
    side = East
    while !isborder(r, North)
        while move_if_possible!(r, side)
            a = 0
            a, border_now = find_special_border!(r, a, border_now, North)
            if a == 1
                t = go_around_rect_and_return_median_t!(r, side)
                #println("Средняя температура текущей рамки: " * string(t))
                my_ans = max(my_ans, t)
            end
        end

        side = inverse_side(side)
        move!(r, North)
        
    end
    
    return my_ans
end

function go_around_rect_and_return_median_t!(r::Robot, side::HorizonSide)
    move!(r, inverse_side(side))
    sum_of_temp = 0
    n = 0
    for i in (inverse_side(side), North, side, South)
        while isborder(r, clockwise_side(i) ) && !isborder(r, i)
            sum_of_temp += temperature(r)
            putmarker!(r)
            n += 1
            move!(r, i)
        end
        sum_of_temp += temperature(r)
        putmarker!(r)
        n += 1
        move!(r, clockwise_side(i))
    end
    move!(r, side)
    #println("Отладочная информация. Клеток в периметре: " * string(n))
    return sum_of_temp / n
end 

function go_inside_rect_and_return_median_t!(r::Robot, side::HorizonSide)
    sum_of_temp = 0
    n = 0
    for i in (North, inverse_side(side), South, side)
        while isborder(r, counterclockwise_side(i) ) && !isborder(r,i)
            sum_of_temp += temperature(r)
            n += 1
            move!(r, i)
        end
    end
    println("Отладочная информация. Клеток в периметре: " * string(n))
    return sum_of_temp / n
end 

function find_special_border!(r::Robot, my_ans::Int, border_now::Bool, side::HorizonSide)
    if isborder(r, side)
        border_now = true
    end
    if !isborder(r, side) && border_now
        border_now = false
        my_ans += 1
    end
    return my_ans, border_now
end