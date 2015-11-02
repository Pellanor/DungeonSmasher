// Based on http://www.appzeit.com/unrealengine/277-unrealengine-4-boids-implementation-in-c-pt1-overview 

#include "DungeonSmasher.h"
#include "Boid.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ABoid::ABoid(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("BoidMesh"));

	static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_AssetPlatform.M_AssetPlatform'"));

	mesh->SetStaticMesh(StaticMesh.Object);
	mesh->SetMaterial(0, Material.Object);
	mesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.5f));
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	velocity = FVector(FMath::RandRange(-5.0f, 5.0f), FMath::RandRange(-5.0f, 5.0f), FMath::RandRange(-5.0f, 5.0f));

}

// Called every frame
void ABoid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	SetActorLocation(GetActorLocation() + velocity * DeltaTime);
	SetActorRotation((UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetActorLocation() + velocity)).Add(270.0f, 0.0f, 0.0f));

}

