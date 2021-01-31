function lab_21(r)
    go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)

    horizontal = 0
    vertical = 0

    border_ver = false
    border_hor = false
    side = East

    while !isborder(r, North)
        while move_if_possible!(r, side)
            horizontal, border_hor = find_special!(r, horizontal, border_hor, North)
            vertical, border_ver = find_special!(r, vertical, border_ver, West)
        end

        horizontal, border_hor = find_special!(r, horizontal, border_hor, North)
        vertical, border_ver = find_special!(r, vertical, border_ver, West)

        side = inverse_side(side)

        move!(r, North)
    end

    return horizontal, vertical
end

function find_special!(r::Robot, my_ans::Int, border_now::Bool, side::HorizonSide)
    if isborder(r, side)
        border_now = true
    end
    if !isborder(r, side) && border_now
        border_now = false
        my_ans += 1
    end
    return my_ans, border_now
end
