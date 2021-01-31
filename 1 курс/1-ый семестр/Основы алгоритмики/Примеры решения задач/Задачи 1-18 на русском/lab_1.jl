function крест_из_маркеров(r::Robot)
    #  \in -> ∈    
    for i ∈ 0:3
        маркировать_направление_и_вернуться_по_маркерам(r,HorizonSide(i))
    end
    putmarker!(r)
end

function маркировать_направление_и_вернуться_по_маркерам(r::Robot, side::HorizonSide) 
    while isborder(r,side)==false
        move!(r,side)
        putmarker!(r)
    end
    side=инвертировать_направление(side)
    while ismarker(r)==true 
        move!(r,side)
    end
end

println("основная функция: крест_из_маркеров(r::Robot)")