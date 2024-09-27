#include "autons/auton_functions.h"
#include "utility/pid_control.h"
#include "robot-config.h"
#include "main.h"
#include "iostream"

double newTurnVelocity;
namespace auton {
    double tileDistanceInch = 23.5625;
    double baseWheelDiameter = 3.5;
    double wheelGearTeeth = 48.0;
    double motorGearTeeth = 36.0;

    double heading_convert(double heading){
        return(heading > 180) ? heading - 360 : heading;
        /*twenRY Operator A = (condition) ? (true data) : (false data)*/
    }

    //the higher the value, the faster the robot will move forward/backward or turn 
    //the lower the value, the robot will wiggle 
   double sped = 0.075;
    void driveAndTurn(double tiles, double angle, double linearMaxVelocity, double turnMaxVelocity, double timeoutMs){
        // 23.5625
        double distanceDegree = tiles * (tileDistanceInch / 1.0) * (1.0 / (M_PI * baseWheelDiameter)) * (wheelGearTeeth / 1.0) * (1.0 / motorGearTeeth) * (360.0 / 1.0);
        double initLeftMoterDegree = leftmo.position(degrees);
        double initRightMoterDegree = rightmo.position(degrees);
        // PIDControl drivePID(sped, 0, 0, 2);
        PIDControl drivePID(sped, 0, 0, 2);
        // PIDControl drivePID(0.06, 0, 0, 2);
        // PIDControl rotateToPID(0.47, 0, 0, 2);
        PIDControl rotateToPID(0.50, 0.0, 0.05, 2);
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && (!drivePID.reachedGoal() || !rotateToPID.reachedGoal())) {
            // Get linear velocity
            double currentLeftMotorDegree = leftmo.position(degrees);
            double currentRightMotorDegree = rightmo.position(degrees);
            double leftTraveledDegree = currentLeftMotorDegree - initLeftMoterDegree;
            double rightTraveledDegree = currentRightMotorDegree - initRightMoterDegree;
            double averageTraveledDegree = (leftTraveledDegree+rightTraveledDegree)/2;
            double error = distanceDegree - averageTraveledDegree;
            drivePID.computeFromError(error);
            double newLinearVelocity = drivePID.getValue();
            newLinearVelocity = fmax(-linearMaxVelocity, fmin(linearMaxVelocity, newLinearVelocity));

            // Get turning velocity
                double rotateError = angle - bob.rotation(deg);
                rotateToPID.computeFromError(rotateError);
                newTurnVelocity = rotateToPID.getValue();
                newTurnVelocity = fmax(-turnMaxVelocity, fmin(turnMaxVelocity, newTurnVelocity));
            // Get final velocity
            double finalLeftVelocity = newLinearVelocity + newTurnVelocity;
            double finalRightVelocity = newLinearVelocity - newTurnVelocity;
            // double finalLeftVelocity = newTurnVelocity - newLinearVelocity;
            // double finalRightVelocity = newLinearVelocity + newTurnVelocity;
            driveVelocity(finalLeftVelocity, finalRightVelocity);

            task::sleep(20);
        }
        leftmo.stop();
        rightmo.stop();
    }
    void chasuturn(double leftPct, double rightPct, double angle, double timeoutMs){
        PIDControl rotateToPID(0.35, 0.0, 0.05, 2);
        // PIDControl rotateToPID();
        timer timeout;
        double errormax = angle - bob.rotation(degrees);       
        while(timeout.time(msec) <= timeoutMs && !rotateToPID.reachedGoal()){
            double error = angle - bob.rotation(degrees);

            double errorScale = error/errormax;
            rotateToPID.computeFromError(error);
            //double newTurnVelocity = rotateToPID.getValue(); 
            driveVelocity(leftPct * errorScale, rightPct * errorScale);
            printf("error=%.1f |" , error ); 
            printf(" imu=%.1f\n",bob.heading(degrees)); 
        
            task::sleep(20); 

        }
        printf(" endimu=%.1f\n",bob.heading(degrees)); 
        leftmo.stop(hold);
        rightmo.stop(hold);
    }
    void turnToAngle(double angle, double MaxVelocity, double timeoutMs){
        PIDControl rotateToPID(0.35, 0.0, 0.05, 2);
        // PIDControl rotateToPID();
        timer timeout;
        while(timeout.time(msec) <= timeoutMs && !rotateToPID.reachedGoal()){
            double error = angle - bob.rotation(degrees);
            rotateToPID.computeFromError(error);
            double newTurnVelocity = rotateToPID.getValue(); 
            driveVelocity(newTurnVelocity, -newTurnVelocity); 
            printf("error%3f\n",error); 
            task::sleep(20); 

        }
        leftmo.stop();
        rightmo.stop();
    }
    void driveVelocity(double leftPct, double rightPct){
        // double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
        double scale = 1;
        leftPct *= scale;
        rightPct *= scale;
        leftmo.spin(fwd, leftPct, pct);
        rightmo.spin(fwd, rightPct, pct);
    }
    // void driveVelocity(double leftPct, double rightPct, double leftRatio, double rightRatio){
    //     double scale = 100.0 / fmax(100.0, fmax(fabs(leftPct), fabs(rightPct)));
    //     leftPct = leftPct *scale*(leftRatio/fmax(leftRatio, rightRatio));
    //     rightPct = rightPct *scale*(rightRatio/fmax(leftRatio, rightRatio));
    //     leftmo.spin(fwd, leftPct, pct);
    //     rightmo.spin(fwd, rightPct, pct);
    // }
    void setHeading(int degree){
        bob.setHeading(degree, degrees);
    }
    void suk(int speed){
        inta.spin(reverse, speed, pct);
    }
    void unsuk(int speed){
        inta.spin(fwd, speed, pct);
    }
}
