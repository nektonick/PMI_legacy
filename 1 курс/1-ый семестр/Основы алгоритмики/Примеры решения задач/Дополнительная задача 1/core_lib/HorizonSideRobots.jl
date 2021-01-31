# HorizonSideRobots.jl

# DATE: 2020 09 12 15-03

module HorizonSideRobots # "Робот на клетчатом поле со сторонами горизонта"

export HorizonSide, Nord, Sud, West, Ost, Robot, move!, isborder, putmarker!, ismarker, temperature, 
show, show!, save, sitedit, sitedit!, sitcreate

"""
    @enum HorizonSide Nord=0 West=1 Sud=2 Ost=3

-- Определяет стороны горизонта на клетчатом поле с Роботом: Nord - Север (вверху), West - Запад (слева), Sud - Юг (внизу), Ost - Восток (справа)     
"""
@enum HorizonSide Nord=0 West=1 Sud=2 Ost=3

ANIMATION_SLEEP_TIME=0.01 

include("SituationDatas.jl")

using .SituationDatas

"""
    r = Robot(;animate=false) 

    r = Robot(num_rows::Integer, num_colons::Integer; animate=false)
    
    r = Robot(file_name::AbstractString; animate=false)

-- Конструктор объектов типа `Robot` (исполнитель "Робот на клетчатом поле со сторонами горизонта типа HorizonSide"):

.    - в первом случае - пустое ограниченное поле будет иметь размер 11х12 и Робот будет - в левом нижнем углу

.    - во втором случае - поле будет иметь указанные размеры

.    - в третьем случае - обстановка загружается из указанного файла

-- Если `animate`=`true`, то при этом открывается окно с соответствующей начальной обстановкой 
(которую можно будет редактировать, и результат редактирования будет сохраняться в файлах "untitled.sit", "untitled.sit.png"). 
Иначе просто создается объект, соодержащий данные, определяющие эту обстановку (визуализации обстановки в этом случае нет).

Командный интерфейс исполнителя (объекта) типа Robot: `move!`, `isboarder`, `putmarker`, `ismarker`, `temperature`, `show`, `show!` (см. help)

Для подготовительной работы с sit-файлами (в этих файлах сохраняется данные с информацией о некоторой обстановке на поле с Роботом) 
имеются специальные функции: `show!`, `sitedit`, `sitcreate` (см. `help`)

"""
mutable struct Robot
    situation::SituationData
    animate::Bool # если true, то - имеет место непрерывная визуализация смены обстановки при выполнении команд Робота
    actualfigure::Union{Nothing,Figure}
    Robot(sit::SituationData;animate=false) = begin 
        if animate==true 
            SituationDatas.sitedit!(sit, "untitled.sit")  
        end 
        new(sit,animate,nothing) 
    end
    Robot(frame_size::Tuple{Integer,Integer}=(UInt(11),UInt(12));animate=false) = Robot(SituationData(frame_size),animate=animate) 
    Robot(num_rows::Integer,num_colons::Integer;animate=false) = Robot((num_rows,num_colons);animate=animate) 
    Robot(file_name::AbstractString;animate=false) = Robot(SituationData(file_name);animate=animate) 
end

"""
    move!(r::Robot, side::HorizonSide)::Nothing

-- Перемещает Робота в соседнюю клетку в заданном направлении (если только на пути нет перегoродки, в противном случае - прерывание)
"""
function move!(r::Robot, side::HorizonSideRobots.HorizonSide)
    if isborder(r,side)==true   
        error("Робот врезался в перегородку при попытке сделать шаг в направлении $(side)") 
    end
    r.situation.robot_position = adjacent_position(r.situation.robot_position, side)
    if r.animate==true 
        draw(r.situation; newfig=false) 
        sleep(ANIMATION_SLEEP_TIME)
    end
    return nothing
end

"""
    isborder(r::Robot, side::HorizonSide)::Bool

-- Проверяет наличие перегородки в заданном направлении
"""
function isborder(r::Robot,side::HorizonSideRobots.HorizonSide)::Bool
    i,j = position(r)
    imax,jmax = r.situation.frame_size
    if (i<1 && j<1)||(i<1 && j>jmax)||(i>imax && j>jmax)||(i>imax && j<1) # - (i,j) - за пределами фрейма (в угловых секторах)
        return false # ни в каких направлениях перепятствий быть не может (т.к. на периметре фрейма не может быть перегородок, отличных от сплошной рамки)                
    elseif i<1 && 1<=j<=jmax # - (i,j) - за пределами фрейма (в северном секторе)
        if side ∈ (Nord,Sud)
            return false # в этих двух направлениях перепятствий быть не может (т.к. на периметре фрейма не может быть перегородок, отличных от сплошной рамки) 
        end
        return side ∈ r.situation.borders_map[1,j] # i=1
    elseif 1<=i<=imax && j>jmax # - (i,j) - за пределами фрейма (в восточном секторе)
        if side ∈ (Ost,West)
            return false # в этих двух направлениях перепятствий быть не может (т.к. на периметре фрейма не может быть перегородок, отличных от сплошной рамки) 
        end   
        return side ∈ r.situation.borders_map[i,jmax] # j=jmax       
    elseif i>imax && 1<=j<=jmax # - (i,j) - за пределами фрейма (в южном секторе)
        if side ∈ (Nord,Sud)
            return false # в этих двух направлениях перепятствий быть не может (т.к. на периметре фрейма не может быть перегородок, отличных от сплошной рамки) 
        end      
        return side ∈ r.situation.borders_map[imax,j] # i=imax
    elseif 1<=i<=imax && j<1 # - (i,j) - за пределами фрейма (в западном секторе)
        if side ∈ (Ost,West)
            return false # в этих двух направлениях перепятствий быть не может (т.к. на периметре фрейма не может быть перегородок, отличных от сплошной рамки)            
        end      
        return side ∈ r.situation.borders_map[i,1] # j=1
    else # - (i,j) - в пределах фрейма (is_inside(r) == true)
        if r.situation.is_framed == true
            if side==Nord && i==1 || side==Sud && i==imax || side==West && j==1 || side==Ost && j==jmax
                return true # - Робот рядом с внешней рамкой и направление - в сторону рамку
            end
        end 
        return is_inner_border(r.situation.robot_position, side, r.situation.borders_map)[1] # side ∈ r.situation.borders_map[i,j]
    end
end # function isborder

"""
    putmarker!(r::Robot)::Nothing

-- Ставит маркер в клетке с Роботом
"""
putmarker!(r::Robot)::Nothing = begin 
    push!(r.situation.markers_map, position(r))
    if r.animate == true 
        draw(r.situation;newfig=false) 
    end
    return nothing 
end
        
"""
    ismarker(r::Robot)::Bool

-- Проверяет наличие маркера в клетке с Роботом
"""
ismarker(r::Robot)::Bool = position(r) ∈ r.situation.markers_map 
    
"""
    temperature(r::Robot)::Int

-- Возвращает значение "температуры" клетки с Роботом (на самом деле, всюду за пределами видимой части поля температура равна 0)
"""
temperature(r::Robot)::Int = is_inside(r) ? r.situation.temperature_map[position(r)...] : 0

import Base.show
"""
    show(r::Robot)::Nothing

-- Открывает окно с текущей обстановкой на поле с Роботом, при этом невозможно редактирование обстановки с помощью мыши 
(устанавливать/снимать перегородки и/или маркеры, перемещать Робота). Если же необходимо иметь возможность 
редактировать показанную обстановку, то вместо show(::Robot) следует использовать функцию show!(::Robot)

    show(sitfile::AbstractString)::Nothing

-- Открывает окно с текущей обстановкой на поле с Роботом, загруженной непосредственно из файла. 
Редактирование обстановки невозможно (для редактирования sit-файлов имеется специальная функция sitedit).    
"""
function show(r::Robot) 
    pre_show_actions(r)
    draw(r.situation; newfig=true) 
    r.actualfigure=gcf()
end

"""
    show!(r::Robot)::Nothing

-- Открывает окно с текущей обстановкой на поле с Роботом, и предоставляет возможность редактирования
 обстановки с помощью мыши (устанавливать/снимать перегородки и/или маркеры, перемещать Робота).
 Результ редактирования автоматически сохраняется в файлах "temp.sit" и "temp.sit.png" 
"""
function show!(r::Robot)
    pre_show_actions(r)
    SituationDatas.sitedit!(r.situation,"temp.sit")
    # обеспечена возможность редактирования с помощью мыши отображаемой обстановки и немедленного сохранения каждого акта редактирвания в файле temp.sit 
    r.actualfigure=gcf()
    return nothing 
end

function pre_show_actions(r::Robot)
    if r.animate==true
        error("В режиме Robot(...;animate==true) невозможен вызов show(::Robot,...)")
    end
    if isnothing(r.actualfigure)==false
        close(r.actualfigure)
        @warn("Окно с предыдущей обстановкой при открытии нового было автоматически закрыто")
    end
end

show(sitfile::AbstractString) = sitfile!="temp.sit" ? show(Robot(sitfile)) : (@warn "Просмотр temp.sit возможен только с помощью show(::Robot;...)")

"""
    save(r::Robot, sitfile::AbstractString)::Nothing

-- сохраняет обстановку на поле с Роботом в указанном текстовом файле    
"""
save(r::Robot, outfile::AbstractString)=save(r.situation,outfile)

"""
    sitedit(infile::AbstractString; outfile=infile)::Nothing

-- предназначена для визуального (с помощью мыши) редактирования обстановки на поле с Роботом, предварительно сохраненной в sit-файле. 
Результат редактирования сохраняется в 2-х форматах: в outfile (sit-файле) и в файле outfile*".png" (в формате png)
"""
function sitedit(infile::AbstractString; outfile=infile)
    global BUFF_SITUATION, IS_FIXED_ROBOT_POSITION
    BUFF_SITUATION=SituationData(infile) #; show(BUFF_SITUATION)
    SituationDatas.sitedit!(BUFF_SITUATION, outfile)
end

"""
    sitcreate(num_rows::Integer,num_colons::Integer; newfile="untitled.sit")::Nothing

-- предназначена для создания и визуального (с помощью мыши) редактирования нового sit-файле (содержащего данные некоторой обстановки на поле сроботом). 
Результат редактирования сохраняется в 2-х форматах: в newfile (sit-файле) и в файле newfile*".png" (в формате png)   
"""    
sitcreate(num_rows::Integer,num_colons::Integer; newfile="untitled.sit") = SituationDatas.sitedit!(SituationData((num_rows, num_colons)), newfile)

"""
    sitedit!(r::Robot,sitfile::AbstractString)

-- позволяет транслировать в уже имеющийся объект типа Robot обстановку из файла
"""
SituationDatas.sitedit!(r::Robot,sitfile::AbstractString) = begin 
    r.situation=SituationData(sitfile)
    if r.animate == true 
        draw(r.situation;newfig=false) 
    end
end

# вспомогательные функции:
is_inside(r::Robot) = SituationDatas.is_inside(r.situation) # - проверяет, находится ли Робот в фрейме (в наблюдаемой части поля)
position(r::Robot) = r.situation.robot_position # - возвращает текущую позицию Робота, т.е. - пару индексов (i,j)

end # module HorizonSideRobots
