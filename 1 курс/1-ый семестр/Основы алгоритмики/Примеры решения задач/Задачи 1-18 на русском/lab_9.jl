function найти_маркер_на_поле(r::Robot)
    число_шагов_в_направлении=1
    side=Nord
    while ismarker(r)==false
        for _ in 1:2
            идти_по_спирали(r,side,число_шагов_в_направлении)
            side=следующее_против_часовой_стрелки_направление(side)
        end
        число_шагов_в_направлении+=1
    end
end
function идти_по_спирали(r::Robot,side::HorizonSide,num::Int)
    for _ in 1:num
        if ismarker(r)
            return nothing
        end
        move!(r,side)
    end
end
println("основная функция: найти_маркер_на_поле(r::Robot)")
