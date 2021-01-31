function маркировать_приграничные_клетки_крестом(r::Robot)
    num=0
    сдвиги_по_осям=[]
    while ((isborder(r,Sud))&&(isborder(r,West)))==false
        push!(сдвиги_по_осям,пройти_и_вернуть_шаги(r,West))
        push!(сдвиги_по_осям,пройти_и_вернуть_шаги(r,Sud))
        num+=2
    end
    num_ver=0
    num_hor=0
    for i in 1:num
        if isodd(i)==true
            num_hor+=сдвиги_по_осям[i]
        else
            num_ver+=сдвиги_по_осям[i]
        end
    end
    side=Nord
    for _ in 1:2
        num_ver=поставить_текущий_маркер_и_венуть_оставшееся_расстояние(r,side,num_ver)
        side=следующее_по_часовой_стрелке_направление(side)
        num_hor=поставить_текущий_маркер_и_венуть_оставшееся_расстояние(r,side,num_hor)
        side=следующее_по_часовой_стрелке_направление(side)
    end
    while (num>0)==true
        side=isodd(num) ? Ost : Nord
        пройти_несколько_шагов(r,side,сдвиги_по_осям[num])
        num-=1
    end
end

function поставить_текущий_маркер_и_венуть_оставшееся_расстояние(r::Robot, side::HorizonSide, num_steps::Int)
    пройти_несколько_шагов(r,side,num_steps)
    putmarker!(r)
    num_steps=пройти_и_вернуть_шаги(r,side)
    return num_steps
end

println("основная функция: маркировать_приграничные_клетки_крестом(r::Robot)")