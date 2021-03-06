#pragma once

#include "OceanPluginPrivatePCH.h"
#include "OceanManager.h"
#include "BuoyancyComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = Movement, meta = (BlueprintSpawnableComponent), HideCategories = (PlanarMovement, "Components|Movement|Planar", Velocity))
class UBuoyancyComponent : public UMovementComponent
{
	GENERATED_UCLASS_BODY()

	/* OceanManager used by the component, if unassign component will auto-detect */
	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "Buoyancy Settings")
	AOceanManager* OceanManager;
	
	/* Density of mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	float MeshDensity;

	/* Density of water */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	float FluidDensity;

	/* Linear damping when object is in fluid */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	float FluidLinearDamping;

	/* Angular damping when object is in fluid */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	float FluidAngularDamping;

	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "Buoyancy Settings")
	FVector VelocityDamper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	bool ClampMaxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	float MaxUnderwaterVelocity;

	/* Radius of the points */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	float TestPointRadius;

	/* Test point array. At least one point is required for buoyancy */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buoyancy Settings")
	TArray<FVector> TestPoints;

	/* Per-point mesh density override, can be used for half-sinking objects etc. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Buoyancy Settings")
	TArray<float> PointDensityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Buoyancy Settings")
	bool DrawDebugPoints;

	/* Stay upright physics constraint (inspired by UDK's StayUprightSpring) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Buoyancy Settings")
	bool EnableStayUprightConstraint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Buoyancy Settings")
	float StayUprightStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Buoyancy Settings")
	float StayUprightDamping;

	//Begin UActorComponent Interface
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	virtual void InitializeComponent() override;
	//End UActorComponent Interface

private:

	static FVector GetVelocityAtPoint(UPrimitiveComponent* Target, FVector Point, FName BoneName = NAME_None);

	float _SignedRadius;
	float _baseAngularDamping;
	float _baseLinearDamping;

};
