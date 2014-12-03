//
//  Particle.cpp
//  ParticleSample
//
//  Created by 上原伸一 on 2014/12/03.
//
//

#include "Particle.h"

//初期化
Particle::Particle(){
    setInitialCondition(0,0,0,0);
    damping = 0.01f;
}

//力（加速度）をリセット
void Particle::resetForce(){
    frc.set(0, 0);
}

//力を加える
void Particle::addForce(float x, float y){
    frc.x += x;
    frc.y += y;
}

//抵抗力の計算
void Particle::addDampingForce(){
    frc.x -= vel.x * damping;
    frc.y -= vel.y * damping;
}

//初期状態を設定
void Particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px, py);
    vel.set(vx, vy);
}

//更新
void Particle::update(){
    vel += frc;
    pos += vel;
}

//描画
void Particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}

bool Particle::outWindow(){
    if (pos.x < 0|| pos.x > ofGetWidth() || pos.y < 0 || pos.y > ofGetHeight())
        return true;
    return false;
}