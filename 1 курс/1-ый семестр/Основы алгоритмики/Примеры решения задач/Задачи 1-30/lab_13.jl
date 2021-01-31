function lab_13(r::Robot)
    for i in ((North, East), (North, West), (South, East), (South, West))
        go_special!(r, i)
        return_special!(r, i)
    end
    putmarker!(r)
end

function return_special!(r,side) 
    while (ismarker(r)) 
        move!(r, inverse_side(side[1]))
        move!(r, inverse_side(side[2]))
    end
end

function go_special!(r, side::NTuple{2,HorizonSide})
    while isborder(r,side[1]) == false  &&   isborder(r,side[2]) == false
        move!(r,side[1])
        move!(r,side[2])
        putmarker!(r)
    end
end