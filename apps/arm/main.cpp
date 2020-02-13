#include "mbed.h"

Motor turnTableMotor(MTR_PWM_TRNTBL, MTR_DIR_TRNTBL, false);
Motor shoulderMotor(MTR_PWM_SHLDR, MTR_DIR_SHLDR, false);
Motor elbowMotor(MTR_PWM_ELBW, MTR_DIR_ELBW, false);
Motor wristLeftMotor(MTR_PWM_WRST_LHS, MTR_DIR_WRST_LHS, false);
Motor wristRightMotor(MTR_PWM_WRIST_RHS, MTR_DIR_WRIST_RHS, false);
Motor clawMotor(MTR_PWM_CLAW, MTR_DIR_CLAW, false);

t_encoderConfig turnTableEncoderConfig {
        pin_PWM = ENC_PWM_TRNTBL,
        degreesPerUnit = 360,
        inverted = false
};

t_encoderConfig shoulderEncoderConfig {
        pin_PWM = ENC_PWM_TRNTBL,
        degreesPerUnit = 360,
        inverted = false
};

t_encoderConfig elbowEncoderConfig {
        pin_PWM = ENC_PWM_TRNTBL,
        degreesPerUnit = 360,
        inverted = false
};

t_encoderConfig wristLeftEncoderConfig {
        // Quadrature encoder pins
        pin_ChannelA = ENC_QUAD_WRST_LHS_A,
        pin_ChannelB = ENC_QUAD_WRST_LHS_A,

        degreesPerUnit = 1.0,
        inverted = false
};

t_encoderConfig wristRightEncoderConfig {
        // Quadrature encoder pins
        pin_ChannelA = ENC_QUAD_WRST_RHS_A,
        pin_ChannelB = ENC_QUAD_WRST_RHS_B,

        degreesPerUnit = 1.0,
        inverted = false
};

t_encoderConfig clawEncoderConfig {
        // Quadrature encoder pins
        pin_ChannelA = ENC_CLAW_QUAD_A,
        pin_ChannelB = ENC_CLAW_QUAD_B,

        degreesPerUnit = 1.0,
        inverted = false
};

EncoderAbsolute_PWM turnTableEncoder(turnTableEncoderConfig);
EncoderAbsolute_PWM shoulderEncoder(shoulderEncoderConfig);
EncoderAbsolute_PWM elbowEncoder(elbowEncoderConfig);

EnocderRelative_Quadrature wristLeftEncoder(wristLeftEncoderConfig);
EncoderRelative_Quadrature wristRightEncoder(wristRightEncoderConfig);
EncoderRelative_Quadrature clawEncoder(clawEncoderConfig);

DigitalIn turnTableLimLeft(LIM_TRNTBL_LHS);
DigitalIn turnTableLimRight(LIM_TRNTBL_RHS);
DigitalIn elbowLimUp(LIM_ELBW_UP);
DigitalIn elbowLimDown(LIM_ELBW_DN);
DigitalIn wristLimUp(LIM_WRST_UP);
DigitalIn wristLimDown(LIM_WRST_DN);
DigitalIn wristLimCenter(LIM_WRST_CNTR);
DigitalIn clawLimOpen(LIM_CLAW_OPEN);

t_actuatorConfig turnTableAcutuatorConfig {
    velocityPID = {
        P = 1.0, 
        I = 0.0,
        D = 0.0, 
        bias = 0.0;
        deadZoneError = 0.1;
    }, 

    positionPID = {
        P = 1.0, 
        I = 0.0,
        D = 0.0, 
        bias = 0.0;
        deadZoneError = 0.1;
    }
};

t_actuatorConfig shoulderAcutuatorConfig {
    velocityPID = {
        P = 1.0, 
        I = 0.0,
        D = 0.0, 
        bias = 0.0;
        deadZoneError = 0.1;
    }, 

    positionPID = {
        P = 1.0, 
        I = 0.0,
        D = 0.0, 
        bias = 0.0;
        deadZoneError = 0.1;
    }
};

t_actuatorConfig elbowAcutuatorConfig {
    velocityPID = {
        P = 1.0, 
        I = 0.0,
        D = 0.0, 
        bias = 0.0;
        deadZoneError = 0.1;
    }, 

    positionPID = {
        P = 1.0, 
        I = 0.0,
        D = 0.0, 
        bias = 0.0;
        deadZoneError = 0.1;
    }
};

ActuatorController(t_actuatorConfig actuatorConfig, 
                       Motor * motor, Encoder * encoder, 
                       DigitalIn * limSwitchMin = NULL, 
                       DigitalIn * limSwitchMax = NULL);


int main()
{
    while (true) {
        led1 = !led1;
        wait_ms(k_interval_ms);
    }
}
