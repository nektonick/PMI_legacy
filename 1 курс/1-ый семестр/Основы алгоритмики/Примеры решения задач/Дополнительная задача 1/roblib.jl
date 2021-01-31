# Используем более привычные английские названия сторон света вместо немецких
""" Север """
North = Nord
""" Юг """
South = Sud
#""" Запад """ - уже определён
#West = West
""" Восток """
East = Ost

"""
mutable struct Robot_for_labyrinth

robot::Robot - Обычный робот  
move_side::HorizonSide - Напрвление, в котором будет двигаться робота
count_of_external_corners::Int - Количество встреченных "внешних" углов. (Углы, по 270 градусов относительно робота) 
count_of_internal_corners::Int - Количество встреченных "внутренних" углов. (Углы, по 90 градусов относительно робота) 
start_point_border_position::HorizonSide - Информация о том, с какой стороны от робота на старте находилась граница либиринта. Нужна, чтобы понять, что робот обошёл лабиринт
previos_state::HorizonSide - Информация о том, где на прошлом шаге от робота находилась граница. Нужна для обхода лабиринта.
MyRobot(r::Robot) = new(r, North, 0, 0 North, North) - конструктор структуры, в который надо передать обычного робота. Остальные поля инициализируются дефолтными значениями

"""
mutable struct Robot_for_labyrinth
    robot::Robot 
    move_side::HorizonSide 
    count_of_external_corners::Int
    count_of_internal_corners::Int
    start_point_border_position::HorizonSide 
    previos_state::HorizonSide 
    Robot_for_labyrinth(r::Robot) = new(r, North, 0, 0, North, North) 

end

"""
get_start_point_border_position(r::Robot_for_labyrinth) :: HorizonSide

Функция, определяющая, с какой стороны от робота имеется граница.
Возвращает первое из направлений, считая с Юга против часовой стрелки.
"""
function get_border_position(r::Robot_for_labyrinth) :: HorizonSide
     
    for i in (South , East, North, West)
        if (isborder(r.robot, i))
            return i
        end
    end
    return North
end

"""
get_move_side(r::Robot_for_labyrinth) :: HorizonSide

Определяет, в какую сторону* при старте надо двигаться роботу.
*В этом направлении может быть граница, это будет нормально, тогда робот "повернёт"
"""
function get_move_side(r::Robot_for_labyrinth) :: HorizonSide
    return next_side(get_border_position(r))
end


"""
show_ans(r::Robot_for_labyrinth) 

Печатает ответ, на основе данных из робота.
"""
function show_ans(r::Robot_for_labyrinth) 
    if (r.count_of_external_corners > r.count_of_internal_corners)
        println("Робот снаружи лабиринта")
    elseif (r.count_of_external_corners < r.count_of_internal_corners)
        println("Робот внутри лабиринта")
    else
        println("Похоже, что лабиринт вырожденный")
    end
end

"""
update_corners_count!(r::Robot_for_labyrinth)

Если текущая клетка является углом, увеличивает соответственню переменную Robot_for_labyrinth на 1
"""
function update_corners_count!(r::Robot_for_labyrinth)
    if get_type_of_corner(r) == 1
        r.count_of_external_corners += 1
        println("внешний угол")
    elseif get_type_of_corner(r) == 2
        r.count_of_internal_corners += 1
        println("внутрениий угол")
    end
end

"""
get_type_of_corner(r::Robot_for_labyrinth) :: Int

Вовзращает 0, если робот не находится в углу, 
возвращает 1, если робот во внешнем углу, 
возвращает 2, если робот во внутреннем углу.
"""
function get_type_of_corner(r::Robot_for_labyrinth) :: Int
    ans = 0
    for i in (North, East, South, West)
        if (isborder(r.robot, i) && isborder(r.robot, HorizonSide(mod(Int(i)-1,4))))
            ans =  2
        end
    end
    
    if (isborder(r.robot, r.previos_state) == false )
        ans = 1
    end
    return ans
end

"""
one_step_move_around_labyrinth!(r::Robot_for_labyrinth)

Перемещает робота на 1 шаг вдоль лабиринта, меняет направление движения в зависимости от типа текущего угла.

"""
function one_step_move_around_labyrinth!(r::Robot_for_labyrinth)
    if !(isborder(r.robot, r.move_side))
        move!(r.robot, r.move_side)
    end
    r.previos_state = prev_side(r.move_side)

    if get_type_of_corner(r) == 1
        change_move_side_to_prev_side!(r)
    elseif get_type_of_corner(r) == 2
        change_move_side_to_next_side!(r)
    end
    
end

"""
change_move_side_to_next_side!(r::Robot_for_labyrinth)

Изменяет сторону движения на следующую
"""
function change_move_side_to_next_side!(r::Robot_for_labyrinth)
    r.move_side = next_side(r.move_side)
end

"""
change_move_side_to_prev_side!(r::Robot_for_labyrinth)

Изменяет сторону движения на предыдущую
"""
function change_move_side_to_prev_side!(r::Robot_for_labyrinth)
    r.move_side = prev_side(r.move_side)
end


"""
Возвращает следующую сторону
"""
next_side(side::HorizonSide)::HorizonSide = HorizonSide(mod(Int(side)+1,4))


"""
Возвращает предыдущую сторону
"""
prev_side(side::HorizonSide)::HorizonSide= HorizonSide(mod(Int(side)-1,4))