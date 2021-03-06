
#ifndef SOUNDKONVERTER_CODEC_MPLAYER_H
#define SOUNDKONVERTER_CODEC_MPLAYER_H

#include "../../core/codecplugin.h"

class ConversionOptions;


class soundkonverter_codec_mplayer : public CodecPlugin
{
    Q_OBJECT
public:
    /** Default Constructor */
    soundkonverter_codec_mplayer( QObject *parent, const VARG_TYPE& args );

    /** Default Destructor */
    ~soundkonverter_codec_mplayer();

    QString name() const;

    QList<ConversionPipeTrunk> codecTable();

    bool isConfigSupported( ActionType action, const QString& format );
    void showConfigDialog( ActionType action, const QString& format, QWidget *parent );
    bool hasInfo();
    void showInfo( QWidget *parent );
    CodecWidget *newCodecWidget();

    int convert( const KUrl& inputFile, const KUrl& outputFile, const QString& inputCodec, const QString& outputCodec, const ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false );
    QStringList convertCommand( const KUrl& inputFile, const KUrl& outputFile, const QString& inputCodec, const QString& outputCodec, const ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false );
    float parseOutput( const QString& output );

private:
   QStringList fromCodecs;
   QStringList toCodecs;
   QMap<QString,QString> codecMap;

};

#ifndef SOUNDKONVERTER_KF5_BUILD
K_EXPORT_SOUNDKONVERTER_CODEC( mplayer, soundkonverter_codec_mplayer )
#endif


#endif // SOUNDKONVERTER_CODEC_MPLAYER_H


