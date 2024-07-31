// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "FPSCameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UFPSCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:
	UFPSCameraComponent(const FObjectInitializer& ObjectInitializer);
	virtual void OnRegister() override;
};
