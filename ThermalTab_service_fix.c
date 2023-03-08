uint16_t SysMecFanGetMinRpm()
{
    uint16_t MinRpm=800;
    int id = system_model_uid;
    DPRINTF(DEBUG_THERM_TABLE, ("@@@@ Id = %d\n",id));

    switch (id)
    {
        case AIO_UMA_24IN:
            MinRpm = 400;
            break;
        case AIO_DGFX_24IN:
            MinRpm = 500;
            break;
        default:
            break;
    }
    return MinRpm;
}