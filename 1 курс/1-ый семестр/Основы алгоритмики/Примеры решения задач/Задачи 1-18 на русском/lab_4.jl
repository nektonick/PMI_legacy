function маркировать_поле_лесенкой(r::Robot)
    x=пройти_и_вернуть_шаги(r,West)
    y=пройти_и_вернуть_шаги(r,Sud)
    i=0
    while isborder(r,Nord)==false
        маркировать_ряд_с_отступом_n_клеток_справа(r,i)
        i=i+1
        move!(r,Nord)
    end
    маркировать_ряд_с_отступом_n_клеток_справа(r,i)
    while isborder(r,Sud)==false
        move!(r,Sud)
    end
    пройти_несколько_шагов(r,Nord,y)
    пройти_несколько_шагов(r,Ost,x)
end

function маркировать_ряд_с_отступом_n_клеток_справа(r::Robot,n::Int)
    while isborder(r,Ost)==false
        move!(r,Ost)
    end
    while isborder(r,West)==false
        if n<=0
            putmarker!(r)
        end
        move!(r,West)
        n=n-1
    end
    putmarker!(r)
end


println("основная функция: маркировать_поле_лесенкой(r::Robot)")