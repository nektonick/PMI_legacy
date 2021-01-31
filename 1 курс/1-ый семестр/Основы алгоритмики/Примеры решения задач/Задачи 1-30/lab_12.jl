function lab_12(r::Robot, cell_size::Int)
    path = go_to_west_south_corner_and_return_path!(r)
    x=0; y=0
    horisontalDirection = East
    
    while !(isborder(r, North) && isborder(r, East))
        marker_special!(r, x, y, cell_size)
        if move_up_condition(r)
            move!(r, North)
            y += 1
            marker_special!(r, x, y, cell_size)
            horisontalDirection = inverse_side(horisontalDirection)
        end
        
        move!(r,horisontalDirection)
        (horisontalDirection == East) ? x += 1 : x -= 1
    end

    marker_special!(r, x, y, cell_size)

    go_to_west_south_corner_and_return_path!(r)
    go_by_path!(r, path)
end

function marker_special!(r, x, y, cell_size)
    if (mod(x, 2 * cell_size)) < cell_size && (mod(y, 2 * cell_size)) < cell_size || 
        (mod(x + cell_size, 2 * cell_size)) < cell_size && (mod(y, 2 * cell_size)) >= cell_size
        putmarker!(r)
    end
end

function move_up_condition(r)
    return isborder(r, East) || isborder(r, West) && !(isborder(r, South) && isborder(r, West))
end