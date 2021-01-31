function маркировать_углы_поля(r::Robot)
    num_steps=[]
    while isborder(r,Sud)==false || isborder(r,West)==false
        push!(num_steps,пройти_и_вернуть_шаги(r,West))
        push!(num_steps,пройти_и_вернуть_шаги(r,Sud))
    end
    for side in (Nord, Ost, Sud, West)
        пройти_и_вернуть_шаги(r,side)
        putmarker!(r)
    end
    i=1
    k=length(num_steps)
    i +=Int(isodd(k))

    for n in 1:k
        i=i+1
        t=isodd(i)
        side=Nord
        if t
            side=Ost
        end
        пройти_несколько_шагов(r,side,num_steps[k-n+1])
    end 
end

println("основная функция: маркировать_углы_поля(r::Robot)")