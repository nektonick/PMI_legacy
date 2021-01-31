function lab_7(r::Robot)
    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)

    is_marker_now = iseven(get_path_length(path)) 

    side = East
    while !(isborder(r, North) && isborder(r, side))
        if (is_marker_now)
            putmarker!(r)
        end
        
        if !(isborder(r, side))
            move!(r,side)
            is_marker_now = !is_marker_now  
        end

        if move_up_condition(r)
            if (is_marker_now)
                putmarker!(r)
            end
            move!(r, North)
            is_marker_now = !is_marker_now
            
            side = inverse_side(side)
        end  
    end
    if is_marker_now
        putmarker!(r)
    end

    go_to_west_south_corner_and_return_path!(r)
    go_by_path!(r, path)

end

function move_up_condition(r::Robot)::Bool
    return (isborder(r, East) || isborder(r, West)) && !(isborder(r,North))
end