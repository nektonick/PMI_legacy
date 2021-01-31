"""
line_side - направление линий маркеров
ortogonal_line_side -  направление для движения робота
"""
function mark_zebra!(robot, line_side, ortogonal_line_side, num_passes, num_start_passes = 0)
    start_side = get_start_side(line_side, ortogonal_line_side)
    #УТВ: start_side - кортеж типа NTuple{2,HorizonSide}, например: (Sud,Ost)  

    path = go_to_some_corner_and_return_path!(r, start_side[1], start_side[2]; go_around_barriers = true)
    #УТВ: Робот - в стартовом углу

    
    side_to_move = (typeof(ortogonal_line_side) == Tuple{HorizonSide,HorizonSide}) ? ortogonal_line_side[1] : ortogonal_line_side
    movements_if_posible!(robot, side_to_move, num_start_passes) || return ErrorException("Неверное направление")
    #УТВ: робот пропустил нужное количество начальных строк, если это возможно

    line_mark!(robot, line_side)
    #УТВ: линия с Роботом и все подходящие предыдущие (по ходу движения в направлении ortogonal_line_side) замаркированы
    while movements_if_posible!(robot, side_to_move, num_passes+1 + Bool(typeof(ortogonal_line_side) == Tuple{HorizonSide,HorizonSide}))
        # маркируем в обе стороны.
        line_side = inverse_side(line_side)
        line_mark!(robot, line_side)
    end
    #УТВ: все линии замаркированы


    go_to_some_corner_and_return_path!(r, start_side[1], start_side[2]; go_around_barriers = true)
    #УТВ: Робот - снова в стартовом углу

    go_by_path!(r, path)
    #УТВ: Робот - в исходном положении
end

function movements_if_posible!(r, side, max_num_steps)
    ans = true
    for _ in 1:max_num_steps
        ans = ans && move_if_possible!(r,side)
    end
    return ans
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
    while move_if_possible!(r,side)
        steps += 1
        putmarker!(r)
    end
    while steps > 0
        move_if_possible!(r, inverse_side(side))
        steps -= 1
    end
end

putmarkers!(r::Robot, side::HorizonSide) =  
    while move_if_possible!(r,side)
        putmarker!(r)
    end

import .move!
move!(r::Robot,side::NTuple{2,HorizonSide}) = 
    for i in side 
        move!(r, i) 
    end
import .isborder

isborder(r::Robot,side::NTuple{2,HorizonSide}) = isborder(r,side[1]) || isborder(r,side[2])


function inverse_side(side::NTuple{2,HorizonSide})::NTuple{2,HorizonSide}
    return (HorizonSide(mod(Int(side[1])+2, 4)), HorizonSide(mod(Int(side[2])+2, 4)) )
end

function clockwise_side(side::NTuple{2,HorizonSide})::NTuple{2,HorizonSide}
    return (HorizonSide(mod(Int(side[1])-1,4)), HorizonSide(mod(Int(side[2])-1,4)))
end

function counterclockwise_side(side::NTuple{2,HorizonSide})::NTuple{2,HorizonSide}
    return (HorizonSide(mod(Int(side[1])+1,4)), HorizonSide(mod(Int(side[2])+1,4)))
end


function move_if_possible!(r::Robot, direct_side::NTuple{2,HorizonSide})::Bool
    my_ans = true
    a = 0
    error_step = 0
    for i in direct_side
        a += 1
        orthogonal_side = counterclockwise_side(i)
        reverse_side = inverse_side(orthogonal_side)
        num_steps=0
        if isborder(r,i)==false
            move!(r,i)
            result=true
        else
            while isborder(r,i) == true
                if isborder(r, orthogonal_side) == false
                    move!(r, orthogonal_side)
                    num_steps += 1
                else
                    break
                end
            end
            if isborder(r,i) == false
                move!(r,i)
                while isborder(r,reverse_side) == true
                    move!(r,i)
                end
                result = true
            else
                result = false
                error_step = a
            end

            while num_steps>0
                num_steps=num_steps-1
                move!(r,reverse_side)
            end

        end
        my_ans = my_ans && result
    end
    if my_ans == false && error_step == 2
        move_if_possible!(r, inverse_side(direct_side[1]))
    elseif my_ans == false && error_step == 1
        move_if_possible!(r, inverse_side(direct_side[2]))
    end
    return my_ans
end
