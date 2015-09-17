float calc_resistance(int count, char conn, float *array)
{
    float totalResistance = 0.0;
    
    if(array == 0 || count == 0 || !(conn == 'S' || conn == 'P'))
        return -1;
    
    for(int i = 0; i < count; i++)
    {
        if(conn == 'P')
        {
            if(array[i] == 0)
                return 0.0;
            // Add the resistors conductance
            totalResistance += 1 / array[i];
        }
        else
            totalResistance += array[i];
    }

    // Turn the total conductance into total resistance
    if(conn == 'P')
        totalResistance = 1 / totalResistance;

    return totalResistance;
}
