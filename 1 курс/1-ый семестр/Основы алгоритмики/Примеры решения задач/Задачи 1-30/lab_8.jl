function lab_8(r::Robot)
    side = Ost
    while isborder(r,North)==true
        putmarker!(r)
        go_by_markers(r,side)
        side=inverse_side(side)
    end
    println("Passage found")
end

function go_by_markers(r::Robot,side::HorizonSide)
    while ismarker(r)==true
        move!(r,side)
    end
end
