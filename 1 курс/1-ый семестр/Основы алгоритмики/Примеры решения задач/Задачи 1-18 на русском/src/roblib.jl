инвертировать_направление(side::HorizonSide) = HorizonSide(mod(Int(side)+2, 4))
следующее_против_часовой_стрелки_направление(side::HorizonSide) = HorizonSide(mod(Int(side)+1,4))
следующее_по_часовой_стрелке_направление(side::HorizonSide) = HorizonSide(mod(Int(side)-1,4))

function маркировать_направление(r,side::HorizonSide)
    while isborder(r,side)==false
        putmarker!(r)    
        move!(r,side)
    end
    putmarker!(r)
end

function перейти_в_правый_верхний_угол(r::Robot)
    while isborder(r,Nord)==false
        move!(r,Nord)
    end
    while isborder(r,Ost)==false
        move!(r,Ost)
    end
end

function перейти_в_левый_нижний_угол(r::Robot)
    while isborder(r,West)==false || isborder(r,Sud)==false
        if isborder(r,West)==false
            move!(r,West)
        end
        if isborder(r,Sud)==false
            move!(r,Sud)
        end
    end
end

function пройти_и_вернуть_шаги(r::Robot,side::HorizonSide) :: Int
    n=0
    while isborder(r,side)==false
        move!(r,side)
        n=n+1
    end 
    return n
end

function пройти_несколько_шагов(r::Robot,side::HorizonSide,n::Int)
    while n>0
        move!(r,side)
        n=n-1
    end
end

function перейти_в_правый_верхний_угол_и_вернуть_путь(r::Robot) ::Array
    путь=[]
    while isborder(r,Nord)==false || isborder(r,Ost)==false
        if isborder(r,Nord)==false
            move!(r,Nord)
            push!(путь,Sud)
        end
        if isborder(r,Ost)==false
            move!(r,Ost)
            push!(путь,West)
        end
    end
    return путь
end

function перейти_в_левый_нижний_угол_и_вернуть_путь(r::Robot) ::Array
    путь=[]
    while isborder(r,Sud)==false || isborder(r,West)==false
        if isborder(r,Sud)==false
            move!(r,Sud)
            push!(путь,Nord)
        end
        if isborder(r,West)==false
            move!(r,West)
            push!(путь,Ost)
        end
    end
    return путь
end

function пройти_по_пути(r,путь::Array)
    n=length(путь)
    while n>0
        move!(r,путь[n])
        n=n-1
    end
end

function смещение_на_x_y_вправо_вверх(r,x,y)
    for i in 1:x
        move!(r,Ost)
    end
    for j in 1:y
        move!(r,Nord)
    end
end

function перейти_в_левый_нижний_угол_и_вернуть_x_y(r::Robot)
    x=0
    y=0
    while isborder(r,West)==false
        move!(r,West)
        x=x+1
    end
    while isborder(r,Sud)==false
        move!(r,Sud)
        y=y+1
    end
    return (x,y)
end

function пройти_в_направлении_если_возможно(r::Robot, direct_side::HorizonSide)::Bool
    orthogonal_side = следующее_по_часовой_стрелке_направление(direct_side)
    reverse_side = инвертировать_направление(orthogonal_side)
    num_steps=0
    if isborder(r,direct_side)==false
        move!(r,direct_side)
        result=true
    else
        while isborder(r,direct_side) == true
            if isborder(r, orthogonal_side) == false
                move!(r, orthogonal_side)
                num_steps += 1
            else
                break
            end
        end
        if isborder(r,direct_side) == false
            move!(r,direct_side)
            while isborder(r,reverse_side) == true
                move!(r,direct_side)
            end
            result = true
        else
            result = false
        end
        while num_steps>0
            num_steps=num_steps-1
            move!(r,reverse_side)
        end
    end
    return result
end
