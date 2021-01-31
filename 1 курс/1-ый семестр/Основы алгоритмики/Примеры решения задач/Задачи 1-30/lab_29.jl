function lab_29(r::Robot)
    println("Функция не совсем корректно отображает многоугольники, но работает корректно с изолированными линиями")
    # Берём за координату пересечение линий слева снизу от робота
    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)
    
    x = go_to_border_come_back_and_return_distance!(r, East) + 1
    y = go_to_border_come_back_and_return_distance!(r, Nord) + 1
    
    x_0 = - ceil(x/2)
    y_0 = - ceil(y/2)
    p = plot()
    
    # внешняя рамка
    plot!(p, x_0:ceil(x/2) , [ y_0 for i in x_0:ceil(x/2) ] )
    plot!(p, [ x_0 for i in y_0:ceil(y/2) ], y_0:ceil(y/2) )
    plot!(p, x_0:ceil(x/2) , [ ceil(y/2) - Int(isodd(y)) for i in x_0:ceil(x/2) ] )
    plot!(p, [ ceil(x/2) - Int(isodd(x)) for i in x_0:ceil(x/2) ] , y_0:ceil(y/2) )

    side = East
    start = Nothing
    finish = Nothing

    # так как самая нижняя граница нас не интересует, поднимаемся на 1 клетку вверх
    move!(r, North)
    y_0 += 1
    
    border_now = isborder(r, South) 
    # наносим горизонтальные линии
    while !(isborder(r, North) && isborder(r, side))
        if !isborder(r,side)
            move!(r, side)
            x_0 += (side == East) ? 1 : -1
        else
            a = get_path_length_in_direction(around_move_return_path!(r, side), side)
            if a != 0 
                x_0 += (side == East) ? a : -a
            else
                move!(r, North)
                y_0 += 1
                side = inverse_side(side)
                
            end
        end
        start, finish, border_now = find_special_border!(r, x_0, y_0, start, finish, border_now, South)

        if finish != Nothing && start != Nothing
            if side == East
                plot!(p, start[1]:finish[1], [ finish[2] for i in start[1]:finish[1] ] )
            else
                plot!(p, finish[1]+1:start[1]+1, [ finish[2] for i in finish[1]:start[1] ] )
            end
            start = Nothing
            finish = Nothing
        end
    end

    go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)
    x_0 = - ceil(x/2)
    y_0 = - ceil(y/2)
    move!(r, East)
    x_0 += 1
    border_now = isborder(r, West) 
    side = North
    # так как самая левая граница нас не интересует, поднимаемся на 1 клетку вверх

    # анологично наносим вертикальные линии
     while !(isborder(r, East) && isborder(r, side))
        if !isborder(r,side)
            move!(r, side)
            y_0 += (side == North) ? 1 : -1
        else
            a = get_path_length_in_direction(around_move_return_path!(r, side), side)
            if a != 0 
                y_0 += (side == North) ? a : - a
            else
                move!(r, East)
                x_0 += 1
                side = inverse_side(side)
                
            end
        end
        start, finish, border_now = find_special_border!(r, x_0, y_0, start, finish, border_now, West)
        if finish != Nothing && start != Nothing
            if side == North
                plot!(p, [ finish[1] for i in start[2]:finish[2] ], start[2]:finish[2]  )
            else
                plot!(p, [ finish[1] for i in finish[2]:start[2] ], finish[2]+1:start[2]+1  )
            end
            start = Nothing
            finish = Nothing
        end
    end
    
    display(p)
    go_by_path!(r, path)
end

function find_special_border!(r::Robot, x, y, start_c, finish_c, border_now::Bool, side::HorizonSide)
    if isborder(r, side) && !border_now 
        border_now = true
        start_c = (x,y)
        finish_c = Nothing
    end
    if !isborder(r, side) && border_now
        border_now = false
        finish_c = (x,y)
    end
    return start_c, finish_c, border_now
end