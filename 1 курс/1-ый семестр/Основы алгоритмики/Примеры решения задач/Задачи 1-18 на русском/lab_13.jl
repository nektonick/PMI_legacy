function маркировать_косой_крест(r::Robot)
    for i in (Nord,Sud)
        for j in (Ost,West)
            пройти_по_диагонали_и_ставить_маркеры(r,i,j)
        end
    end
end

function пройти_по_диагонали_и_ставить_маркеры(r::Robot,side_1::HorizonSide,side_2::HorizonSide)
    k=0
    while isborder(r,side_1)==false && isborder(r,side_2)==false
        putmarker!(r)
        move!(r,side_1)
        move!(r,side_2)
        k=k+1
    end
    putmarker!(r)
    i=инвертировать_направление(side_1)
    j=инвертировать_направление(side_2)
    while k>0 
        k=k-1
        move!(r,i)
        move!(r,j)
    end
end



println("основная функция: маркировать_косой_крест(r::Robot)")