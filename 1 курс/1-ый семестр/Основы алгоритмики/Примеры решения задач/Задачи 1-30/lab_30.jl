function lab_30(r::Robot)
    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)
    y = go_to_border_come_back_and_return_distance!(r, North)

    side = East
    for i ∈ 1:y
        move_spec!(r::Robot, side)
        find_spec!(r::Robot, side)

        side = inverse_side(side)
    end
    move_spec!(r::Robot, side)
    for i ∈ 1:y
        move!(r, South)
    end

    go_by_path!(r, path)
end

function move_spec!(r::Robot, side::HorizonSide)
    putmarker!(r)
    while !isborder(r, inverse_side(side))
        move!(r, inverse_side(side))      
        putmarker!(r)  
    end
    while !isborder(r, side)
        move!(r, side)
        putmarker!(r)
    end
end

function find_spec!(r::Robot, side::HorizonSide)
    if side == West 
        move!(r, North)
    else
        while isborder(r, North)
            move!(r, inverse_side(side))
        end
        move!(r, North)
    end
end