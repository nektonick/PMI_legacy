function lab_23(r)
    go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)

    my_ans = 0
    horizontal = 0
    vertical = 0
    border_now = false
    border_ver = false
    border_hor = false
    side = East

    while !isborder(r, North)
        while move_if_possible!(r, side)
            my_ans, border_now = find_special_rectangle!(r, my_ans, border_now, side)
            horizontal, border_hor = find_special_border!(r, horizontal, border_hor, North)
            vertical, border_ver = find_special_border!(r, vertical, border_ver, West)
        end

        my_ans, border_now = find_special_rectangle!(r, my_ans, border_now, side)
        horizontal, border_hor = find_special_border!(r, horizontal, border_hor, North)
        vertical, border_ver = find_special_border!(r, vertical, border_ver, West)

        side = inverse_side(side)
        move!(r, North)

        my_ans, border_now = find_special_rectangle!(r, my_ans, border_now, side)
        horizontal, border_hor = find_special_border!(r, horizontal, border_hor, North)
        vertical, border_ver = find_special_border!(r, vertical, border_ver, West)
        
    end

    return my_ans, horizontal-my_ans, vertical-my_ans
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

function find_special_rectangle!(r::Robot, my_ans::Int, border_now::Bool, move_side::HorizonSide)
    if isborder(r, North)
        border_now = true
    end
    if !isborder(r, North) && border_now
        border_now = false
       
        move!(r, North)
        if isborder(r, inverse_side(move_side))
            my_ans += 1
        end
        move!(r, South)

    end
    return my_ans, border_now
end