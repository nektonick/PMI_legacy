# Подключаем основной файл робота. Без ниго ничего не работает.
include("core_lib/HorizonSideRobots.jl")
using .HorizonSideRobots

# Файл, со вспомогательными функциями. Нужен, чтобы не загружать "лишним" основной файл
include("roblib.jl")

"""
solve(r::Robot)

Функция, при выполнении которой создаётся специальный робот, который обходит лабиринт и пишет, внутри лабиринта он или снаружи.
"""
function solve!(r::Robot)
    # Инициализируем робота
    lab_rob = Robot_for_labyrinth(r)
    lab_rob.start_point_border_position = get_border_position(lab_rob)
    lab_rob.move_side = get_move_side(lab_rob)
    lab_rob.previos_state = lab_rob.start_point_border_position
    lab_rob.count_of_external_corners = 0
    lab_rob.count_of_internal_corners = 0

    # Ставим маркер в начальной клетке 
    putmarker!(lab_rob.robot)

    start = true
    # Обход лабиринта и подсёт углов
    one_step_move_around_labyrinth!(lab_rob)
    update_corners_count!(lab_rob)
    

    while !(ismarker(lab_rob.robot) && get_border_position(lab_rob) == lab_rob.start_point_border_position && start == false)
        one_step_move_around_labyrinth!(lab_rob)
        if !ismarker(lab_rob.robot)
            start = false;
        end
        update_corners_count!(lab_rob)
    end

    # Вывод ответа
    show_ans(lab_rob)

end
