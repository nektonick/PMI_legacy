function маркировать_всё_поле(r::Robot)
    y=пройти_и_вернуть_шаги(r,Sud)
    x=пройти_и_вернуть_шаги(r,West)

    перейти_в_правый_верхний_угол(r)

    начать_маркировку_поля(r,Sud)
    if isborder(r,Sud)
        маркировать_направление(r,Nord)
    end
    маркировать_направление(r,Sud)

    пройти_несколько_шагов(r,Nord,y)
    пройти_несколько_шагов(r,Ost,x)
end

function начать_маркировку_поля(r::Robot,side::HorizonSide)
    
    while isborder(r,West)==false
        маркировать_направление(r,side)
        side=инвертировать_направление(side)
        move!(r,West)
    end
end

println("основная функция: маркировать_всё_поле(r::Robot)")