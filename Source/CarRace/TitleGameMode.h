// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TitleMenu.h"
#include "TitleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CARRACE_API ATitleGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UTitleMenu> TitleMenuClass;

	UTitleMenu* TitleMenuWidget;

};
