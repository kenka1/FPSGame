// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/FPSCameraComponent.h"

UFPSCameraComponent::UFPSCameraComponent(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
}

void UFPSCameraComponent::OnRegister()
{
	Super::OnRegister();

	UE_LOG(LogTemp, Warning, TEXT("Camera Reigstered"));

	UE_LOG(LogTemp, Warning, TEXT("Name : %s"), *(GetOwner()->GetHumanReadableName()));
}