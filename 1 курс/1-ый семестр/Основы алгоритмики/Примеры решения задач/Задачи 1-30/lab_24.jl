function lab_24(r::Robot)
    go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)

    max_s = 0
    current_w = 0
    current_h = 0 
    border_now = false
    side = East

    while !isborder(r, North)
        while move_if_possible!(r, side)
            current_w, current_h, border_now = find_rectangle_w_h!(r, current_w, current_h, border_now, side)
            if current_h * current_w > max_s
                max_s = current_h * current_w
            end
        end
        current_w, current_h, border_now = find_rectangle_w_h!(r, current_w, current_h, border_now, side)
        if current_h * current_w > max_s
            max_s = current_h * current_w
        end
    

        side = inverse_side(side)
        move!(r, North)
        current_w, current_h, border_now = find_rectangle_w_h!(r, current_w, current_h, border_now, side)
        if current_h * current_w > max_s
            max_s = current_h * current_w
        end
        
    end

    return max_s
end

function find_rectangle_w_h!(r::Robot, x::Int, y::Int, border_now::Bool, move_side::HorizonSide)
    if isborder(r, North) && !border_now
        border_now = true
        x = 0
        y = 0
    end

    if !isborder(r, North) && border_now
        border_now = false
        move!(r, North)
        while isborder(r, inverse_side(move_side)) 
            y += 1
            move!(r, North)
        end
        for i ∈ 1:y
            move!(r, South)
        end
        move!(r, South)

    end

    if border_now
        x += 1
    end

    return x, y, border_now
end