function lab_9(r::Robot)
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
        move!(r,side)
    end
end
