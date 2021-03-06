#ifndef GLOBAL_H
#define GLOBAL_H

#include <QStringList>

namespace VtesInfo
{

    // On déclare les listes contenant la base de connaissance du jeu

    const QStringList DisciplinesList = QStringList()   << "Abombwe" << "Animalism" << "Auspex" << "Celerity" << "Chimerstry" << "Daimonion"
                                                        << "Dementation" << "Dominate" << "Fortitude" << "Melpomine" << "Mytherceria" << "Necromancie"
                                                        << "Obeah" << "Obfuscate" << "Obtenebration" << "Potence" << "Presence" << "Protean"
                                                        << "Quietus" << "Sanguinus" << "Serpentis" << "Spiritus" << "Temporis" << "Thaumaturgie"
                                                        << "Thanatosis" << "Valeren" << "Vicisitude" << "Viseratica" << "Maleficia" << "Striga";

    const QStringList DisciplinesSigleList = QStringList() << "abo" << "ani" << "aus" << "cel" << "chi" << "dai"
                                                           << "dem" << "dom" << "for" << "mel" << "myt" << "nec"
                                                           << "obe" << "obf" << "obt" << "pot" << "pre" << "pro"
                                                           << "qui" << "san" << "ser" << "spi" << "tem" << "tha"
                                                           << "thn" << "val" << "vic" << "vis" << "mal" << "str";

    const QStringList CreedSigleList = QStringList() << "def" << "inn" << "jud" << "mar" << "red" << "ven" << "vis2";

    const QStringList ExpList = QStringList()   << "Keepers of Tradition" << "Legacies of Blood" << "Third Edition" << "Bloodlines" << "Anarchs" << "Sabbat"
                                                << "Ebony Kingdom" << "Camarilla Edition" << "Heirs to the Blood" << "Lords of The Night" << "Ancient Hearts"
                                                << "Final Nights" << "Sword of Caine" << "Dark Sovereigns" << "Black Hand" << "10th Anniversary" << "Sabbat War"
                                                << "Blood Shadow Court" << "Promo" << "Kindred Most Wanted"<<  "Twilight Rebellion" << "Nights of Reckoning" << "The Unaligned";

    const QStringList ClansList = QStringList() << "Abomination" << "Ahrimane" << "Akunanse" << "Assamite" << "Baali" << "Blood Brother" << "Brujah" << "Brujah antitribu"
                                                << "Caitiff" << "Daughters of Cacophony" << "Follower of Set" << "Gangrel" << "Gangrel antitribu" << "Gargoyle"
                                                << "Giovanni" << "Guruhi" << "Harbingers of Skulls" << "Ishtarri" << "Kiasyd" << "Lasombra" << "Malkavian" << "Malkavian antitribu"
                                                << "Nagaraja" << "Nosferatu" << "Nosferatu antitribu" << "Osebo" << "Pander" << "Ravnos" << "Salubri" << "Salubri antitribu"
                                                << "Samedi" << "Toreador" << "Toreador antitribu" << "Tremere" << "Tremere antitribu" << "True Brujah" << "Tzimisce"
                                                << "Ventrue" << "Ventrue antitribu";

    const QStringList CreedList = QStringList() << "Avenger" << "Defender" << "Innocent" << "Judge" << "Martyr" << "Redeemer" << "Visionary";

    const QStringList TitlesList = QStringList() << "Titled" << "Primogen" << "Prince" << "Justicar" << "Inner Circle" << "Bishop"
                                                 << "Archbishop" << "Cardinal" << "Regent" << "Priscus" << "Inquisitor" << "1 vote" << "2 votes"
                                                 << "3 votes" << "Baron" << "Magaji"; //<< "All Titles" //???

    const QStringList SectsList = QStringList() << "Camarilla" << "Sabbat" << "Independent" << "Laibon" << "Imbued";

    const QStringList RarityList = QStringList() << "Common" << "Uncommon" << "Rare";

    const QStringList CardTypeList = QStringList() << "Master" << "Conviction" << "Event" << "Action" << "Political Action"
                                                    << "Equipment" << "Ally" << "Retainer" << "Action Modifier" << "Combat"
                                                    << "Reaction" << "Power" << "Reflex"; // << "Token";

    const QStringList MasterSubTypeList = QStringList() << "Discipline" << "Out-of-turn" << "Location" << "Hunting ground"
                                                        << "Archetype" << "Contract" << "Investment" << "Trophy" << "Watchtower";

    const QStringList EventSubTypeList = QStringList() << "Gehenna" << "Event" << "Government" << "Transient" << "Inconnu" << "Inquisition";

    const QStringList DisciplineLvlList  = QStringList() << "Any" << "inf" << "inf+" << "SUP" << "None";

    const QStringList OperatorList = QStringList() << "=" << "<=" << ">=";

    const QStringList DeckFormat = QStringList() << "Unlimited" << "Limited" << "Free";

    const QStringList MetasList = QStringList() << "name" << "author" << "description" << "format"
                                               << "game_win" << "victory_point" << "tournament_win" << "games_played";

    const QStringList VipedList = QStringList() << "Speed" << "Combat" << "Bleed" << "Diplomacy" << "Defense";

    enum MetaIndex { indexName = 0, indexAuthor, indexdescription, indexFormat,
                     indexGameWin, indexVictoryPoint, indexTournamentWin, indexGamesPlayed};

    enum CardType{ NoType, CryptType, LibraryType, CounterType };

    enum ItemTypes { SortItemType = 1000, LibraryItemType, CryptItemType };

    enum DeckItemRoles { NameRole = Qt::UserRole, SetsRole, ImageFileRole, URLCarteRole, ExpansionRole, RarityRole, TypeRole,
                         SubTypeRole, ClanRole, GroupingRole, CapacityRole, DisciplineRole, SectRole, PCostRole, BCostRole,
                         CCostRole, TitleRole, TraitRole, KeyWordsRole, LimitationRole, TextRole, ArtistRole, CommentaryRole,
                         ExemplairRole, ItemCategoryRole,
                         RegionButtonAddRole};

    enum ExportFormats { format_edb = 0, format_ardb, format_txt };
}

// TODO : en faire une class static !
class PathProvider
{
public:
    explicit PathProvider();
    bool initPaths();
    QString getCardPath();
    QString getDeckPath();

private:
    QString CardPath;
    QString DeckPath;
};

#endif
