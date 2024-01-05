#include "SaturnRingActornew.h"

ASaturnRingActornew::ASaturnRingActornew()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
    RootComponent = MeshComponent;

    InnerRadius = 100.0f;
    OuterRadius = 150.0f;

    SemiMajorAxis = 8000.0f;
    SemiMinorAxis = 7700.0f;
    OrbitSpeed = 7.0f;
    CurrentOrbitAngle = 0.0f;
}

void ASaturnRingActornew::BeginPlay()
{
    Super::BeginPlay();

    GenerateRingMesh();
}

void ASaturnRingActornew::GenerateRingMesh()
{
    TArray<FVector> Vertices;
    TArray<int32> Triangles;
    TArray<FVector> Normals;
    TArray<FVector2D> UVs;

    float AngleIncrement = 2 * PI / NumSegments;

    for (int32 i = 0; i <= NumSegments; ++i)
    {
        float Angle = i * AngleIncrement;
        FVector VertexInner = FVector(FMath::Cos(Angle) * InnerRadius, FMath::Sin(Angle) * InnerRadius, 0.0f);
        FVector VertexOuter = FVector(FMath::Cos(Angle) * OuterRadius, FMath::Sin(Angle) * OuterRadius, 0.0f);

        Vertices.Add(VertexInner);
        Vertices.Add(VertexOuter);

        FVector Normal = FVector(0.0f, 0.0f, 1.0f);
        Normals.Add(Normal);
        Normals.Add(Normal);

        FVector2D UVInner = FVector2D(static_cast<float>(i) / NumSegments, 0.0f);
        FVector2D UVOuter = FVector2D(static_cast<float>(i) / NumSegments, 1.0f);
        UVs.Add(UVInner);
        UVs.Add(UVOuter);

        if (i < NumSegments)
        {
            Triangles.Add(i * 2);
            Triangles.Add(i * 2 + 1);
            Triangles.Add((i + 1) * 2);

            Triangles.Add((i + 1) * 2);
            Triangles.Add(i * 2 + 1);
            Triangles.Add((i + 1) * 2 + 1);

            Triangles.Add(i * 2);
            Triangles.Add((i + 1) * 2);
            Triangles.Add(i * 2 + 1);

            Triangles.Add((i + 1) * 2);
            Triangles.Add((i + 1) * 2 + 1);
            Triangles.Add(i * 2 + 1);
        }
    }

    MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);

    UMaterial* RingMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/Saturn/M_Saturn.M_Saturn'"));
    if (RingMaterial)
    {
        MeshComponent->SetMaterial(0, RingMaterial);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load material for the ring."));
    }
}

void ASaturnRingActornew::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector NewScale = FVector(5.2f, 5.2f, 5.2f);
    RootComponent->SetWorldScale3D(NewScale);

    FRotator NewRotation = GetActorRotation();
    float RotationSpeed = -65.0f;

    NewRotation.Yaw += RotationSpeed * DeltaTime;

    SetActorRotation(NewRotation);


    const FVector NewLocation = FVector(
        SemiMajorAxis * FMath::Cos(FMath::DegreesToRadians(CurrentOrbitAngle)),
        SemiMinorAxis * FMath::Sin(FMath::DegreesToRadians(CurrentOrbitAngle)),
        GetActorLocation().Z
    );

    SetActorLocation(NewLocation);

    CurrentOrbitAngle += OrbitSpeed * DeltaTime;
    if (CurrentOrbitAngle >= 360.0f)
    {
        CurrentOrbitAngle = 0.0f;
    }
}
