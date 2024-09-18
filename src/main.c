#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/video.h>
#include <zephyr/logging/log.h>
#include <zephyr/display/cfb.h>


LOG_MODULE_REGISTER(camera);

static const struct device *camera =
     DEVICE_DT_GET(DT_NODELABEL(ov7670_camera)); 

static const struct device *display =
    DEVICE_DT_GET(DT_NODELABEL(oled0));      

static const struct pwm_dt_spec pwml0 = 
    PWM_DT_SPEC_GET(DT_NODELABEL(pwml0));

void main(void)
{
    int ret;
//         const struct device *dev;
// dev = device_get_binding("ov7670_camera");
    ret = pwm_set_pulse_dt(&pwml0,40);
        if(!device_is_ready(pwml0.dev))
    {
        return;
    }
    if(display == NULL)
    {
        LOG_ERR("device pointer is null");
        return;
    }
    if(!device_is_ready(display))
    {
        LOG_ERR("display note connected");
        return;
    }
    ret=cfb_framebuffer_init(display);
    if(ret!=0)
    {
        LOG_ERR("could not initialize display");
        return;
    }
    ret=cfb_print(display,"Hello world",0,0);
    if(ret!=0)
    {
        LOG_ERR("can't print on oled");
        return;
    }
    ret =cfb_framebuffer_finalize(display);
    if(ret!=0)
    {
        LOG_ERR("could not finalize display");
        return;
    }    
if (camera == NULL) {
    printk("Error: Could not get ov7670 device binding\n");
}
    if(camera == NULL)
    {
        LOG_ERR("pointer NULL");
        return;
    }
     if(!device_is_ready(camera))
     {
        LOG_ERR("camera not connected");
         return;
    }
    while(true)
    {
    }
}