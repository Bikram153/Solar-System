#include "MercuryTrajectory.h"
#include "ProceduralMeshComponent.h"
#include "Engine.h"

ATrajectoryMercury::ATrajectoryMercury()
{
	ProceduralMeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMeshComponent"));
	RootComponent = ProceduralMeshComponent;
}

void ATrajectoryMercury::BeginPlay()
{
	Super::BeginPlay();
	GenerateHollowEllipseMesh();
}

void ATrajectoryMercury::GenerateHollowEllipseMesh()
{
	if (!ProceduralMeshComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProceduralMeshComponent is not valid."));
		return;
	}

	TArray<FVector> Vertices;
	TArray<int32> Triangles;

	const float AngleIncrement = 2.0f * PI / NumSegments;
	const float OuterRadiusX = 4300.0f;
	const float OuterRadiusY = 4000.0f;

	for (int32 i = 0; i <= NumSegments; i++)
	{
		const float Angle = i * AngleIncrement;
		const float X = OuterRadiusX * FMath::Cos(Angle);
		const float Y = OuterRadiusY * FMath::Sin(Angle);

		Vertices.Add(FVector(X, Y, 0.0f));
		Vertices.Add(FVector(X, Y, -10.0f));
	}

	for (int32 i = 0; i <= NumSegments; i++)
	{
		Triangles.Add(i * 2);
		Triangles.Add((i + 1) * 2);
		Triangles.Add(i * 2 + 1);

		Triangles.Add(i * 2 + 1);
		Triangles.Add((i + 1) * 2);
		Triangles.Add((i + 1) * 2 + 1);

		Triangles.Add(i * 2);
		Triangles.Add(i * 2 + 1);
		Triangles.Add((i + 1) * 2 + 1);

		Triangles.Add(i * 2);
		Triangles.Add((i + 1) * 2 + 1);
		Triangles.Add((i + 1) * 2);
	}

	ProceduralMeshComponent->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	ProceduralMeshComponent->ContainsPhysicsTriMeshData(true);
}
