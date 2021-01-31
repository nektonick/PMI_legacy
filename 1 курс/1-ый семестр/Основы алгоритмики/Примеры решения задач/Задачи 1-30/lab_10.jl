function lab_10(r::Robot)
    local_ans = 0
    field_size = 1
    side = East

    local_ans += temperature(r)
    println("temperature here is " * string(temperature(r)))

    while !isborder(r,North)
        while !isborder(r,side) 
            local_ans += special_move(r, side)
            field_size += 1
        end
        local_ans += special_move(r, North)
        
        field_size += 1
        side=inverse_side(side)
    end
    while !isborder(r,side)   
        local_ans += special_move(r, side)
        field_size += 1
    end 
    
    return (local_ans/(field_size))
end

function special_move(r::Robot, side::HorizonSide)
    move!(r,side)
    println("temperature here is " * string(temperature(r)))
    return temperature(r)
end