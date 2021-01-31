function найти_проход_в_перегородке(r::Robot)
    side=Ost
    while isborder(r,Nord)==true
        putmarker!(r)
        идти_по_маркерам(r,side)
        side=инвертировать_направление(side)
    end
    println("проход найден!")
end

function идти_по_маркерам(r::Robot,side::HorizonSide)
    while ismarker(r)==true
        move!(r,side)
    end
end

println("основная функция: найти_проход_в_перегородке(r::Robot)")