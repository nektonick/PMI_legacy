function маркировать_шахматными_клетками_размера_n(r::Robot,n::Int)
    x,y=перейти_в_левый_нижний_угол_и_вернуть_x_y(r)
    пройти_и_вернуть_шаги(r,Nord)
    all=пройти_и_вернуть_шаги(r,Sud)+1
    side=Nord
    t=0
    k=n
    kk=2n
    while isborder(r,Ost)==false
        if t>=k && t<kk
            for i in 1:n
                if isborder(r,side)==false
                    move!(r,side)
                end
            end
        end
        расставить_маркеры_в_направлении(r,side,n,all)
        move!(r,Ost)
        side=инвертировать_направление(side)
        пройти_и_вернуть_шаги(r,side)
        side=инвертировать_направление(side)
        t=t+1
        if t>kk
            k=k+2n
            kk=kk+2n
        end
    end
    if t>=k && t<kk
        for i in 1:n
            if isborder(r,side)==false
                move!(r,side)
            end
        end
    end
    расставить_маркеры_в_направлении(r,side,n,all)
    перейти_в_левый_нижний_угол_и_вернуть_x_y(r)
    смещение_на_x_y_вправо_вверх(r,x,y)
end


function расставить_маркеры_в_направлении(r::Robot,side::HorizonSide,n::Int,all::Int)
    k=0
    ii=0
    while isborder(r,side)==false
        ii=0
        for i in 1:n
            if isborder(r,side)==false
                putmarker!(r)
                move!(r,side)
                k=k+1
                ii=ii+1
            end
        end
        if isborder(r,side)==true && ii!=n
            putmarker!(r)
        end
        for j in 1:n
            if isborder(r,side)==false
                move!(r,side)
                k=k+1
            end
        end
    end
    mm=2n+1
    while all>=mm
        if all==mm
            move!(r,HorizonSide(mod(Int(side)+2,4)))
            if ismarker(r)==false
                move!(r,side)
                putmarker!(r)
            end
        end
        mm=mm+3n
    end

    return k
end

println("основная функция: маркировать_шахматными_клетками_размера_n(r::Robot,n::Int)")