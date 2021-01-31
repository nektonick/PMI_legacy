function крест_из_маркеров_на_поле_с_перегородками(r::Robot)
    for side in (Nord, West, Sud, Ost)
        num_steps = поставить_маркеры_в_направлении_и_вернуть_количество_шагов(r,side)
        несколько_шагов_через_препятствия(r,инвертировать_направление(side), num_steps)
    end
    putmarker!(r)
end


function поставить_маркеры_в_направлении_и_вернуть_количество_шагов(r::Robot,side::HorizonSide)
    num_steps=0 
    while пройти_в_направлении_если_возможно(r, side) == true
        putmarker!(r)
        num_steps += 1
    end 
    return num_steps
end


несколько_шагов_через_препятствия(r::Robot, side::HorizonSide, num_steps::Int) =
for _ in 1:num_steps
    пройти_в_направлении_если_возможно(r,side)
end

println("основная функция: крест_из_маркеров_на_поле_с_перегородками(r::Robot)")