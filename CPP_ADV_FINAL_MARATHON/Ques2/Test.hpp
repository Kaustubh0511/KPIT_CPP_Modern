#include "ResearchOrganisationList.hpp"

void start(ResearchOrgainiasationList &lst)
{
    Mission *mis;

    ResearchOrganisation org1("ISRO");
    org1.AddMission(mis = new Mission("Chandrayaan 1"));
    mis->AddScientist(new Scientist("a1"));
    mis->AddScientist(new Scientist("a2"));
    mis->AddScientist(new Scientist("a3"));

    org1.AddMission(mis = new Mission("Chandrayaan 2"));
    mis->AddScientist(new Scientist("b1"));
    mis->AddScientist(new Scientist("b2"));
    mis->AddScientist(new Scientist("b3"));

    org1.AddMission(mis = new Mission("Chandrayaan 3"));
    lst.AddResearchOrganisation(org1);

    ResearchOrganisation org2("CSIR");
    org2.AddMission(mis = new Mission("economic"));
    org2.AddMission(mis = new Mission("environmental"));
    org2.AddMission(mis = new Mission("societal"));
    lst.AddResearchOrganisation(org2);

    ResearchOrganisation org3("DRDO");
    lst.AddResearchOrganisation(org3);
    ResearchOrganisation org4("ICMR");
    org4.AddMission(mis = new Mission("TribalHealth"));
    org4.AddMission(mis = new Mission("DiseaseInformatics"));
    mis->AddScientist(new Scientist("s1"));
    mis->AddScientist(new Scientist("s2"));
    mis->AddScientist(new Scientist("s3"));
    mis->AddScientist(new Scientist("s4"));
    lst.AddResearchOrganisation(org4);

    ResearchOrganisation org5("BARC");
    org5.AddMission(mis = new Mission("alpha"));
    lst.AddResearchOrganisation(org5);

    // cout << org1;
    // line();
    // cout << org2;
    // line();
    // cout << org3;
    // line();
    // cout << org4;
    // line();
    // cout << org5;
}