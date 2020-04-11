// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "InClass_Week13Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

//Declare a stat group
DECLARE_STATS_GROUP(TEXT("MyStatGroup"), STATGROUP_MyStatGroup, STATCAT_Advanced);

//Custom macro to help declare new cycle counters
#define MyStatGroup_SCOPE_CYCLE_COUNTER(Stat) \
	DECLARE_SCOPE_CYCLE_COUNTER(TEXT(#Stat),Stat,STATGROUP_MyStatGroup)

AInClass_Week13Projectile::AInClass_Week13Projectile() 
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AInClass_Week13Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	//InitialLifeSpan = 3.0f;
}

void AInClass_Week13Projectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//DoSomeWork();
	
	//Only count in scope
	MyStatGroup_SCOPE_CYCLE_COUNTER(STAT_ProjectileTick);

	//Move the same work to C++
	{
		//Only count in scope
		MyStatGroup_SCOPE_CYCLE_COUNTER(STAT_DoingWork);
		WorkResult = 0.f;
		for (int32 i = 0; i < 100000; ++i)
		{
			WorkResult += (((FMath::Sqrt((4.f * 5.f))) / 32.f) * 123.f) * 20.f;
		}
	}

	OnWorkDone(WorkResult);
}

void AInClass_Week13Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		//Destroy();
	}
}