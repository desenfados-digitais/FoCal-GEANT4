// NOTE: Very inefficient code! Will substitute all PVPlacement for PVReplica.

#include "construction.hh"


MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{   
    // Materials

    G4NistManager *nist = G4NistManager::Instance();

    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Material *tungsten = nist->FindOrBuildMaterial("G4_W");
    G4Material *silicon = nist->FindOrBuildMaterial("G4_Si");

    // World Box

    G4Box *solidWorld = new G4Box("solidWorld", .7*m, .7*m, .7*m);      

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld"); 

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0,0,0), logicWorld,"physWorld", 0, false, 0, true);

    // Detector Volumes

    // 1. Tungsten Plates

    G4Box *solidTungstenPlate = new G4Box("solidTungstenPlate", 464, 252, 3.5);

    G4LogicalVolume *logicTungstenPlate = new G4LogicalVolume(solidTungstenPlate, tungsten, "logicTungstenPlate");

    // 1.1 Adding visual attributes

    G4VisAttributes *tungstenVisAttributes = new G4VisAttributes(G4Colour(0.3 ,0.3 ,0.3));
    tungstenVisAttributes->SetForceSolid(true);

    logicTungstenPlate->SetVisAttributes(tungstenVisAttributes);

    // 1.2 Placing physical volumes

    float spacing = 17;

    G4VPhysicalVolume *physTungstenPlate0 = new G4PVPlacement(0,G4ThreeVector(0,0,0*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate1 = new G4PVPlacement(0,G4ThreeVector(0,0,1*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate2 = new G4PVPlacement(0,G4ThreeVector(0,0,2*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate3 = new G4PVPlacement(0,G4ThreeVector(0,0,3*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate4 = new G4PVPlacement(0,G4ThreeVector(0,0,4*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate5 = new G4PVPlacement(0,G4ThreeVector(0,0,5*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate6 = new G4PVPlacement(0,G4ThreeVector(0,0,6*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate7 = new G4PVPlacement(0,G4ThreeVector(0,0,7*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate8 = new G4PVPlacement(0,G4ThreeVector(0,0,8*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physTungstenPlate9 = new G4PVPlacement(0,G4ThreeVector(0,0,9*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, 0, true);

    // 2. Silicon Plates

    G4Box *solidSiliconPlate = new G4Box("solidSiliconPlate", 464, 252, 0.3);

    G4LogicalVolume *logicSiliconPlate = new G4LogicalVolume(solidSiliconPlate, silicon, "logicSiliconPlate");

    // 2.1 Adding visual attributes

    G4VisAttributes *siliconVisAttributes = new G4VisAttributes(G4Colour(1 ,1 ,1));
    siliconVisAttributes->SetForceSolid(true);

    logicSiliconPlate->SetVisAttributes(siliconVisAttributes);

    // 2.2 Placing physical volumes

    float startpoint = 3.5;

    G4VPhysicalVolume *physSiliconPlate0 = new G4PVPlacement(0,G4ThreeVector(0,0,0*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate1 = new G4PVPlacement(0,G4ThreeVector(0,0,1*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate2 = new G4PVPlacement(0,G4ThreeVector(0,0,2*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate3 = new G4PVPlacement(0,G4ThreeVector(0,0,3*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate4 = new G4PVPlacement(0,G4ThreeVector(0,0,4*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate5 = new G4PVPlacement(0,G4ThreeVector(0,0,5*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate6 = new G4PVPlacement(0,G4ThreeVector(0,0,6*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate7 = new G4PVPlacement(0,G4ThreeVector(0,0,7*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate8 = new G4PVPlacement(0,G4ThreeVector(0,0,8*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    G4VPhysicalVolume *physSiliconPlate9 = new G4PVPlacement(0,G4ThreeVector(0,0,9*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, 0, true);

    return physWorld;
};
