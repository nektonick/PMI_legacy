function lab_6(r::Robot)

    path = go_to_west_south_corner_and_return_path!(r; go_around_barriers = true)
    
    side = North
    
    while side != "border"
        side = sneak!(r, side)
    end

    for i in (North, East, South, West)
        while isborder(r, clockwise_side(i) )
            putmarker!(r)
            move!(r, i)
        end
        putmarker!(r)
        move!(r, clockwise_side(i) )
    end 

    go_to_west_south_corner_and_return_path!(r)
    go_by_path!(r, path)
end

function sneak!(r, side)
     
    while !isborder(r, side)
        (isborder(r, East)) ? break : move!(r,side)
    end
    if isborder(r, East)
        my_ans = "border"
    else
        move!(r, East)
        my_ans = inverse_side(side)
    end
    
    return my_ans
end
