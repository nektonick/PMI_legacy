"""
line_side - направление линий маркеров
ortogonal_line_side -  направление для движения робота
"""
function mark_zebra!(robot, line_side, ortogonal_line_side, num_passes, num_start_passes = 0)
    start_side = get_start_side(line_side, ortogonal_line_side)
    #УТВ: start_side - кортеж типа NTuple{2,HorizonSide}, например: (Sud,Ost)  

    path = go_to_some_corner_and_return_path!(r, start_side[1], start_side[2])
    #УТВ: Робот - в стартовом углу

    
    movements_if_posible!(robot, ortogonal_line_side, num_start_passes) || return ErrorException("Неверное направление")
    #УТВ: робот пропустил нужное количество начальных строк, если это возможно

    line_mark!(robot, line_side)
    #УТВ: линия с Роботом и все подходящие предыдущие (по ходу движения в направлении ortogonal_line_side) замаркированы

    while movements_if_posible!(robot, ortogonal_line_side, num_passes+1)
        # маркируем в обе стороны.
        line_side = inverse_side(line_side)
        line_mark!(robot, line_side)
        line_side = inverse_side(line_side)
        line_mark!(robot, line_side)
    end
    #УТВ: все линии замаркированы


    go_to_some_corner_and_return_path!(r, start_side[1], start_side[2])
    #УТВ: Робот - снова в стартовом углу

    go_by_path!(r, path)
    #УТВ: Робот - в исходном положении
end

function movements_if_posible!(robot, side, max_num_steps)
    for _ in 1:max_num_steps
        # из-за ленивых вычислений строка ниже либо возвращает из false, если isborder(robot,side), либо ничего не делает
        isborder(robot,side) && (return false)
        move!(robot,side)
    end
    return true
end

function line_mark!(robot, side)
    putmarker!(robot)
    putmarkers!(robot, side)
end

inverse_side(side::NTuple{2,HorizonSide}) = (HorizonSide(mod(Int(side[1])+2, 4)),HorizonSide(mod(Int(side[2])+2, 4)))

get_start_side(line_side::HorizonSide,ortogonal_line_side::HorizonSide) = inverse_side((line_side, ortogonal_line_side))
get_start_side(line_side::NTuple{2,HorizonSide}, ortogonal_line_side::NTuple{2,HorizonSide}) = inverse_side(ortogonal_line_side)

function putmarkers!(r::Robot,side::NTuple{2,HorizonSide})
    steps = 0
    while !isborder(r,side)
        move!(r,side)
        steps += 1
        putmarker!(r)
    end
    while steps > 0
        move!(r, inverse_side(side))
        steps -= 1
    end
end

putmarkers!(r::Robot, side::HorizonSide) =  
    while !isborder(r,side)
        move!(r, side)
        putmarker!(r)
    end

import .move!
move!(r::Robot,side::NTuple{2,HorizonSide}) = 
    for i in side 
        move!(r, i) 
    end
import .isborder

isborder(r::Robot,side::NTuple{2,HorizonSide}) = isborder(r,side[1]) || isborder(r,side[2])