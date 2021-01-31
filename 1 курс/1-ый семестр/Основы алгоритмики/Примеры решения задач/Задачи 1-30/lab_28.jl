function lab_28(r::Robot)
    steps = 1
    side = North
    while ismarker(r)==false
        for _ in 1:2
            special_move!(r,side,steps)
            side=counterclockwise_side(side)
        end
        steps += 1
    end
    println("Marker found!")
end
function special_move!(r::Robot,side::HorizonSide,num::Int)
    for _ in 1:num
        if ismarker(r)
            return nothing
        end
        isborder(r, side) ? go_around(r, side) : move!(r,side)
    end
end

function go_around(r, direct_side)
    move_side = clockwise_side(direct_side)
    left_moves = 0
    right_moves = 0
    while isborder(r, direct_side)
        left_moves += 1
        right_moves = left_moves
        while isborder(r,direct_side) && right_moves > 0
            right_moves -= 1
            move!(r,move_side)
        end
        side=inverse_side(move_side)
    end
    move!(r,direct_side)
    left_moves /= 2
    while left_moves > 0
        left_moves -= 1
        move!(r,move_side)
    end
end
