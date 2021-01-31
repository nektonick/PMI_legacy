function среднее_значение_температуры_в_клетках_с_маркерами(r::Robot)
    температура=0
    высота_поля=пройти_и_вернуть_шаги(r,Nord)
    ширина_поля=1
    side=Nord
    while isborder(r,Ost)==false 
        n=n+1
        side=инвертировать_направление(side)
        температура += измерить_температуру_в_столбце(r,side)
        move!(r,Ost)
    end
    side=инвертировать_направление(side)
    температура += измерить_температуру_в_столбце(r,side)
    print(температура/(ширина_поля*высота_поля))
    return (температура/(ширина_поля*высота_поля))
end

function измерить_температуру_в_столбце(r,side) :: Number
    n=0
    while isborder(r,side)==false
       n=n+temperature(r) 
       move!(r,side)
    end
    n=n+temperature(r)
    return n
end

println("основная функция: среднее_значение_температуры_в_клетках_с_маркерами(r::Robot)")