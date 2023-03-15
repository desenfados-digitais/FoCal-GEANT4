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

    for (G4int i = 0; i<10; i++)
    {
        G4VPhysicalVolume *physTungstenPlate = new G4PVPlacement(0,G4ThreeVector(0,0,i*spacing), logicTungstenPlate, "physTungstenPlate", logicWorld, false, i, true);
    }

    // 2. Silicon Plates

    G4Box *solidSiliconPlate = new G4Box("solidSiliconPlate", 464, 252, 0.3);

    G4LogicalVolume *logicSiliconPlate = new G4LogicalVolume(solidSiliconPlate, silicon, "logicSiliconPlate");

    // 2.1 Adding visual attributes

    G4VisAttributes *siliconVisAttributes = new G4VisAttributes(G4Colour(1 ,1 ,1));
    siliconVisAttributes->SetForceSolid(true);

    logicSiliconPlate->SetVisAttributes(siliconVisAttributes);

    // 2.2 Placing physical volumes

    float startpoint = 4;

    for (G4int i = 0; i<10; i++)
    {
        G4VPhysicalVolume *physSiliconPlate = new G4PVPlacement(0,G4ThreeVector(0,0,i*spacing + startpoint), logicSiliconPlate, "physSiliconPlate", logicWorld, false, i, true);   
    }

    return physWorld;
};
