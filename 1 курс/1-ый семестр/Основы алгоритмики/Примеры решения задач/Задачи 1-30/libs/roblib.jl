# Файл с наиболее часто использумыми функциями

# Используем более привычные английские названия сторон света вместо немецких
""" 
Север 
"""
North = Nord
"""
Юг 
"""
South = Sud
#Запад - уже определён как West
""" 
Восток
"""
East = Ost

"""
Возвращает инвертированное направление
"""
function inverse_side(side::HorizonSide)::HorizonSide
    return HorizonSide(mod(Int(side)+2, 4))
end

"""
Возвращает следующее по часовой стрелке направление
"""
function clockwise_side(side::HorizonSide)::HorizonSide
    return HorizonSide(mod(Int(side)-1,4))
end

"""
Возвращает следующее против часовой стрелки направление
"""
function counterclockwise_side(side::HorizonSide)::HorizonSide
    return HorizonSide(mod(Int(side)+1,4))
end


"""
go!(r::Robot, side::HorizonSide; steps::Int = 1, go_around_barriers::Bool = false, markers = false)::Int

Перемещает робота в направлении. Возвращает 0, если невозможно пройти в данном направлении, отрицательное число (Если робот обходил препятствия, но в нужной клетке был прямоугольник. Тогда это отрицательное число, равное числу шагов, сделанных роботом, возвращающимся в исходную точку),либо положительное число (Количество реально сделанных шагов в данном направлении). 

Именованные параметры: 
steps - количество шагов в направлении;

go_around_barriers - робот будет по пути обходить перегородки, если такие имеются;

markers - робот будет ставить маркеры по пути (не ставит их при обходе перегородок).
"""
function go!(r::Robot, side::HorizonSide; steps::Int = 1, go_around_barriers::Bool = false, markers = false)::Int
    my_ans = 0
    if markers
        putmarker!(r)
    end
    if (go_around_barriers)
        path = around_move_return_path!(r, side; steps, markers)
        my_ans = get_path_length_in_direction(path, side)
    else
        for i ∈ 1:steps

            if (markers)
                putmarker!(r)
            end

            if !isborder(r, side)
                move!(r, side)
                my_ans += 1
            else
                for i ∈ 1:my_ans
                    move!(r, inverse_side(side))
                end
                my_ans = 0
                break
            end
        end
        if (markers)
            putmarker!(r)
        end
    end

    return my_ans
end

"""
around_move_return_path!(r::Robot, side::HorizonSide; steps::Int = 1, markers = false)::Array{Tuple{HorizonSide,Int64},1}

Вспомогательная функция. Возвращает путь после перемещения робота
"""
function around_move_return_path!(r::Robot, side::HorizonSide; steps::Int = 1, markers = false)::Array{Tuple{HorizonSide,Int64},1}
    path = [ (Nord, 0) ] 
    steps_to_do = steps
    
    while steps_to_do > 0

        if markers
            putmarker!(r)
        end

        path_now = go_around_barrier_and_return_path!(r, side)

        for i in path_now
            push!(path, i)
        end

        steps_to_do -= get_path_length_in_direction(path_now, side)

        if !isborder(r, side) && steps_to_do > 0
            push!(path, ( inverse_side(side), 1))
            move!(r, side)
            steps_to_do -= 1

            if markers
                putmarker!(r)
            end
        elseif get_path_length_in_direction(path_now, side) == 0
            steps_to_do = -1
            break
        end
        if markers && steps_to_do >= 0
            putmarker!(r)
        end
    end
    if steps_to_do < 0 
        my_ans = 0
        # возвращаемся назад
        go_by_path!(r, path)
        path = [ (North, 0) ]
    end

    return path
end

"""
go_to_border_come_back_and_return_distance!(r::Robot, side::HorizonSide; go_around_barriers::Bool = false, markers = false)::Int

Перемещает робота до границы и обратно, возвращая расстояние до границы (ортогональные шаги при обходе перегородок не учитываются)

Именованные параметры: 
go_around_barriers - робот будет по пути обходить перегородки, если такие имеются;

markers - робот будет ставить маркеры по пути (не ставит их при обходе перегородок).
"""
function go_to_border_come_back_and_return_distance!(r::Robot, side::HorizonSide; go_around_barriers::Bool = false, markers = false)::Int
    my_ans = 0
    if go_around_barriers
        # здесь и далее интерпритатор понимает, что я хочу записать в именованный параметр markers вызываемой функции значение из параметра markers текущей функции
        if markers
            putmarker!(r)
        end
        if !isborder(r, side)
            move!(r, side)
            steps = 1
        else
            steps = get_path_length_in_direction(go_around_barrier_and_return_path!(r, side), side)
        end
        my_ans += steps
        if markers
            putmarker!(r)
        end
        while steps > 0
            if !isborder(r, side)
                move!(r, side)
                steps = 1
            else
                steps = get_path_length_in_direction(go_around_barrier_and_return_path!(r, side), side)
            end
            my_ans += steps
        end
        if markers
            putmarker!(r)
        end
        go!(r, inverse_side(side); steps = my_ans, go_around_barriers = true)
    else
        while go!(r, side; markers) > 0
            my_ans += 1
        end
        go!(r, inverse_side(side); steps = my_ans)
    end
    return my_ans
end


"""
go_to_border_and_return_path!(r::Robot, side::HorizonSide; go_around_barriers::Bool = false, markers = false)::Array{Tuple{HorizonSide,Int64},1}

Перемещает робота до границы и возвращает путь для обраного следования в виде массива пар типа (направление, количество шагов)

Именованные параметры: 
go_around_barriers - робот будет по пути обходить перегородки, если такие имеются;

markers - робот будет ставить маркеры по пути (не ставит их при обходе перегородок).
"""
function go_to_border_and_return_path!(r::Robot, side::HorizonSide; go_around_barriers::Bool = false, markers = false)::Array{Tuple{HorizonSide,Int64},1}
    my_ans = [ (North, 0) ]
    if go_around_barriers
        steps = 0
        if markers
            putmarker!(r)
        end
        if !isborder(r, side)
            move!(r, side)
            steps = 1
            push!(my_ans, (inverse_side(side), 1) )
        else
            path = go_around_barrier_and_return_path!(r, side)
            steps = get_path_length_in_direction(path, side)
            for i in path
                push!(my_ans, i)
            end
        end
        if markers
            putmarker!(r)
        end
        while steps > 0
            if !isborder(r, side)
                move!(r, side)
                steps = 1
                push!(my_ans, (inverse_side(side), 1) )
                if markers
                    putmarker!(r)
                end
            else
                path = go_around_barrier_and_return_path!(r, side)
                steps = get_path_length_in_direction(path, side)
                for i in path
                    push!(my_ans, i)
                end
                if markers
                    putmarker!(r)
                end
            end
        end

    else
        steps=0
        steps_now = go!(r,side; markers)
        while steps_now > 0
            steps += steps_now
            steps_now = go!(r,side; markers)
        end
        push!(my_ans, (inverse_side(side), steps) )
    end
    return my_ans
end

"""
go_to_west_south_corner!(r::Robot; go_around_barriers::Bool = false, markers = false)::Array{Tuple{HorizonSide,Int64},1}

Перемещает робота в левый нижний угол и возвращает путь для обраного следования в виде массива пар типа (направление, количество шагов)

Именованные параметры: 
go_around_barriers - робот будет по пути обходить перегородки, если такие имеются;

markers - робот будет ставить маркеры по пути (не ставит их при обходе перегородок).
"""
function go_to_west_south_corner_and_return_path!(r::Robot; go_around_barriers::Bool = false, markers = false)::Array{Tuple{HorizonSide,Int64},1}
    my_ans = []
    a = go_to_border_and_return_path!(r, West; go_around_barriers, markers)
    b = go_to_border_and_return_path!(r, South; go_around_barriers, markers)

    for i in a
        push!(my_ans, i)
    end
    for i in b
        push!(my_ans, i)
    end
    return my_ans
end

function go_to_some_corner_and_return_path!(r::Robot, side_1::HorizonSide, side_2::HorizonSide; go_around_barriers::Bool = false, markers = false)::Array{Tuple{HorizonSide,Int64},1}
    my_ans = []
    a = go_to_border_and_return_path!(r, side_1; go_around_barriers, markers)
    b = go_to_border_and_return_path!(r, side_2; go_around_barriers, markers)

    for i in a
        push!(my_ans, i)
    end
    for i in b
        push!(my_ans, i)
    end
    return my_ans
end


"""
go_by_path!(r::Robot, path::Array{Tuple{HorizonSide,Int64},1})

Перемещает робота по пути. Путь должен быть в формате массива пар (направление, количество шагов).
Путь на корректность не проверяется, что может привести к ошибкам в ходе выполнения.
"""
function go_by_path!(r::Robot, path::Array{Tuple{HorizonSide,Int64},1})
    new_path = reverse(path)
    for i in new_path
        go!(r, i[1]; steps = i[2])
    end
end


"""
go_around_barrier_and_return_path!(r::Robot, direct_side::HorizonSide)::Array{Tuple{HorizonSide,Int64},1}

Обходит барьер, если таковой имеется перед роботом. Возвращает путь для возвращения в формате массива пар (направление, количество шагов).
"""
function go_around_barrier_and_return_path!(r::Robot, direct_side::HorizonSide)::Array{Tuple{HorizonSide,Int64},1}
    my_ans = []
    orthogonal_side = clockwise_side(direct_side)
    reverse_side = inverse_side(orthogonal_side)
    num_of_orthohonal_steps = 0
    num_of_direct_steps = 0

    if !isborder(r, direct_side)
        my_ans = [ (North, 0) ]
    else
        while isborder(r,direct_side) == true
            if isborder(r, orthogonal_side) == false
                move!(r, orthogonal_side)
                num_of_orthohonal_steps += 1
            else
                break
            end
        end        

        if isborder(r,direct_side) == false
            move!(r,direct_side)
            num_of_direct_steps += 1
            while isborder(r,reverse_side) == true
                num_of_direct_steps += 1
                move!(r,direct_side)
            end
            push!(my_ans, (inverse_side(orthogonal_side), num_of_orthohonal_steps) )
            push!(my_ans, (inverse_side(direct_side), num_of_direct_steps) )
            push!(my_ans, (inverse_side(reverse_side), num_of_orthohonal_steps) )
        else
            my_ans = [ (North, 0) ]
        end

        while num_of_orthohonal_steps > 0
            num_of_orthohonal_steps=num_of_orthohonal_steps-1
            move!(r,reverse_side)
        end

    end
    return my_ans
end

"""
get_path_length(path::Array{Tuple{HorizonSide,Int64},1})::Int

Возвращает общую количество шагов в массиве. Массив должен быть в формате пар (направление, количество шагов).
"""
function get_path_length(path::Array{Tuple{HorizonSide,Int64},1})::Int
    my_ans = 0
    for i in path
        my_ans += i[2]
    end
    return my_ans
end


"""
get_path_length_in_direction(path::Array{Tuple{HorizonSide,Int64},1}, direction::HorizonSide)::Int

Возвращает количество шагов в массиве в данном направлении, или в противоположном ему. Массив должен быть в формате пар (направление, количество шагов).
"""
function get_path_length_in_direction(path::Array{Tuple{HorizonSide,Int64},1}, direction::HorizonSide)::Int
    my_ans = 0
    for i in path
        (i[1] == direction || i[1] == inverse_side(direction)) ? my_ans += i[2] : Nothing
    end
    return my_ans
end

"""
move_if_possible!(r::Robot, direct_side::HorizonSide)::Bool

Робот двигается в направлении, если это возможно. Если препятствия нет, робот пройдёт 1 клетку. Иначе, обойдёт препятствие
"""
function move_if_possible!(r::Robot, direct_side::HorizonSide)::Bool
    orthogonal_side = counterclockwise_side(direct_side)
    reverse_side = inverse_side(orthogonal_side)
    num_steps=0
    if isborder(r,direct_side)==false
        move!(r,direct_side)
        result=true
    else
        while isborder(r,direct_side) == true
            if isborder(r, orthogonal_side) == false
                move!(r, orthogonal_side)
                num_steps += 1
            else
                break
            end
        end
        if isborder(r,direct_side) == false
            move!(r,direct_side)
            while isborder(r,reverse_side) == true
                move!(r,direct_side)
            end
            result = true
        else
            result = false
        end
        while num_steps>0
            num_steps=num_steps-1
            move!(r,reverse_side)
        end
    end
    return result
end