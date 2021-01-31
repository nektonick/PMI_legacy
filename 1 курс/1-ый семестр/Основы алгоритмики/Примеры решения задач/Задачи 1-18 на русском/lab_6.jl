function маркировать_внутренний_прямоугольник(r::Robot)

    путь=перейти_в_правый_верхний_угол_и_вернуть_путь(r)
    i=0
    while isborder(r,West)==false
        move!(r,West)
        i=i+1
    end

    n=i
    m=West
    while n==i
        move!(r,Sud)
        n=0
        m=инвертировать_направление(m)
        while isborder(r,m)==false
            move!(r,m)
            n=n+1
        end
    end

    while isborder(r,m)==true
        putmarker!(r)
        move!(r,Sud)
    end

    putmarker!(r)
    move!(r,m)

    while isborder(r,Nord)==true
        putmarker!(r)
        move!(r,m)
    end

    putmarker!(r)
    move!(r,Nord)

    m=инвертировать_направление(m)

    while isborder(r,m)==true
        putmarker!(r)
        move!(r,Nord)
    end

    putmarker!(r)
    move!(r,m)

    while isborder(r,Sud)==true
        putmarker!(r)
        move!(r,m)
    end

    putmarker!(r)

    перейти_в_правый_верхний_угол_и_вернуть_путь(r)
    пройти_по_пути(r,путь)
end



println("основная функция: маркировать_внутренний_прямоугольник(r::Robot)")
