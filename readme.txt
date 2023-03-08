以下是有問題的code,少寫一個break;會導致case AIO_UMA_24IN load到錯誤的MinRpm值
uint16_t SysMecFanGetMinRpm()
{
    int MinRpm=800;
    int id = system_model_uid;
    DPRINTF(DEBUG_THERM_TABLE, ("@@@@ Id = %d\n",id));

    switch (id)
    {
        case AIO_UMA_24IN:
            MinRpm = 400;
        case AIO_DGFX_24IN:
            MinRpm = 500;
            break;
        default:
            break;
    }
    return MinRpm;
}


以下是透過ChatGPT fix後的code,修復遺漏break;的問題,同時也發現了回傳值定義的問題
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
