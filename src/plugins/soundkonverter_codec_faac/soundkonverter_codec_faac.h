
#ifndef SOUNDKONVERTER_CODEC_FAAC_H
#define SOUNDKONVERTER_CODEC_FAAC_H

#include "../../core/codecplugin.h"

#include <QWeakPointer>
#include <QDateTime>

class ConversionOptions;


class soundkonverter_codec_faac : public CodecPlugin
{
    Q_OBJECT
public:
    /** Default Constructor */
    soundkonverter_codec_faac( QObject *parent, const VARG_TYPE& args );

    /** Default Destructor */
    ~soundkonverter_codec_faac();

    QString name() const;
    int version();

    QList<ConversionPipeTrunk> codecTable();

    bool isConfigSupported( ActionType action, const QString& codecName );
    void showConfigDialog( ActionType action, const QString& codecName, QWidget *parent );
    bool hasInfo();
    void showInfo( QWidget *parent );

    CodecWidget *newCodecWidget();

    int convert( const KUrl& inputFile, const KUrl& outputFile, const QString& inputCodec, const QString& outputCodec, const ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false );
    QStringList convertCommand( const KUrl& inputFile, const KUrl& outputFile, const QString& inputCodec, const QString& outputCodec, const ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false );
    float parseOutput( const QString& output );

private:
    QWeakPointer<KProcess> infoProcess;
    QString infoProcessOutputData;

    int configVersion;
    QDateTime faacLastModified;
    bool faacHasMp4Support;

private slots:
    void infoProcessOutput();
    void infoProcessExit( int exitCode, QProcess::ExitStatus exitStatus );
};

#ifndef SOUNDKONVERTER_KF5_BUILD
K_EXPORT_SOUNDKONVERTER_CODEC( faac, soundkonverter_codec_faac )
#endif


#endif // _SOUNDKONVERTER_CODEC_FAAC_H_


