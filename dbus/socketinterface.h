/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -N -m -i generic-types.h -p socketinterface /home/ndr/projects/libsystemd-qt/dbus/introspection/org.freedesktop.systemd1.Socket.xml
 *
 * qdbusxml2cpp is Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef SOCKETINTERFACE_H_1364660292
#define SOCKETINTERFACE_H_1364660292

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "generic-types.h"

/*
 * Proxy class for interface org.freedesktop.systemd1.Socket
 */
class OrgFreedesktopSystemd1SocketInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.systemd1.Socket"; }

public:
    OrgFreedesktopSystemd1SocketInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OrgFreedesktopSystemd1SocketInterface();

    Q_PROPERTY(bool Accept READ accept)
    inline bool accept() const
    { return qvariant_cast< bool >(property("Accept")); }

    Q_PROPERTY(uint Backlog READ backlog)
    inline uint backlog() const
    { return qvariant_cast< uint >(property("Backlog")); }

    Q_PROPERTY(bool BindIPv6Only READ bindIPv6Only)
    inline bool bindIPv6Only() const
    { return qvariant_cast< bool >(property("BindIPv6Only")); }

    Q_PROPERTY(QString BindToDevice READ bindToDevice)
    inline QString bindToDevice() const
    { return qvariant_cast< QString >(property("BindToDevice")); }

    Q_PROPERTY(bool Broadcast READ broadcast)
    inline bool broadcast() const
    { return qvariant_cast< bool >(property("Broadcast")); }

    Q_PROPERTY(QByteArray CPUAffinity READ cPUAffinity)
    inline QByteArray cPUAffinity() const
    { return qvariant_cast< QByteArray >(property("CPUAffinity")); }

    Q_PROPERTY(int CPUSchedulingPolicy READ cPUSchedulingPolicy)
    inline int cPUSchedulingPolicy() const
    { return qvariant_cast< int >(property("CPUSchedulingPolicy")); }

    Q_PROPERTY(int CPUSchedulingPriority READ cPUSchedulingPriority)
    inline int cPUSchedulingPriority() const
    { return qvariant_cast< int >(property("CPUSchedulingPriority")); }

    Q_PROPERTY(bool CPUSchedulingResetOnFork READ cPUSchedulingResetOnFork)
    inline bool cPUSchedulingResetOnFork() const
    { return qvariant_cast< bool >(property("CPUSchedulingResetOnFork")); }

    Q_PROPERTY(QString Capabilities READ capabilities)
    inline QString capabilities() const
    { return qvariant_cast< QString >(property("Capabilities")); }

    Q_PROPERTY(qulonglong CapabilityBoundingSet READ capabilityBoundingSet)
    inline qulonglong capabilityBoundingSet() const
    { return qvariant_cast< qulonglong >(property("CapabilityBoundingSet")); }

    Q_PROPERTY(DBusCGroupAttrs ControlGroupAttributes READ controlGroupAttributes)
    inline DBusCGroupAttrs controlGroupAttributes() const
    { return qvariant_cast< DBusCGroupAttrs >(property("ControlGroupAttributes")); }

    Q_PROPERTY(bool ControlGroupModify READ controlGroupModify)
    inline bool controlGroupModify() const
    { return qvariant_cast< bool >(property("ControlGroupModify")); }

    Q_PROPERTY(bool ControlGroupPersistent READ controlGroupPersistent)
    inline bool controlGroupPersistent() const
    { return qvariant_cast< bool >(property("ControlGroupPersistent")); }

    Q_PROPERTY(QStringList ControlGroups READ controlGroups)
    inline QStringList controlGroups() const
    { return qvariant_cast< QStringList >(property("ControlGroups")); }

    Q_PROPERTY(uint ControlPID READ controlPID)
    inline uint controlPID() const
    { return qvariant_cast< uint >(property("ControlPID")); }

    Q_PROPERTY(QString DefaultControlGroup READ defaultControlGroup)
    inline QString defaultControlGroup() const
    { return qvariant_cast< QString >(property("DefaultControlGroup")); }

    Q_PROPERTY(uint DirectoryMode READ directoryMode)
    inline uint directoryMode() const
    { return qvariant_cast< uint >(property("DirectoryMode")); }

    Q_PROPERTY(QStringList Environment READ environment)
    inline QStringList environment() const
    { return qvariant_cast< QStringList >(property("Environment")); }

    Q_PROPERTY(DBusExecCommand ExecStartPost READ execStartPost)
    inline DBusExecCommand execStartPost() const
    { return qvariant_cast< DBusExecCommand >(property("ExecStartPost")); }

    Q_PROPERTY(DBusExecCommand ExecStartPre READ execStartPre)
    inline DBusExecCommand execStartPre() const
    { return qvariant_cast< DBusExecCommand >(property("ExecStartPre")); }

    Q_PROPERTY(DBusExecCommand ExecStopPost READ execStopPost)
    inline DBusExecCommand execStopPost() const
    { return qvariant_cast< DBusExecCommand >(property("ExecStopPost")); }

    Q_PROPERTY(DBusExecCommand ExecStopPre READ execStopPre)
    inline DBusExecCommand execStopPre() const
    { return qvariant_cast< DBusExecCommand >(property("ExecStopPre")); }

    Q_PROPERTY(bool FreeBind READ freeBind)
    inline bool freeBind() const
    { return qvariant_cast< bool >(property("FreeBind")); }

    Q_PROPERTY(QString Group READ group)
    inline QString group() const
    { return qvariant_cast< QString >(property("Group")); }

    Q_PROPERTY(int IOScheduling READ iOScheduling)
    inline int iOScheduling() const
    { return qvariant_cast< int >(property("IOScheduling")); }

    Q_PROPERTY(int IPTOS READ iPTOS)
    inline int iPTOS() const
    { return qvariant_cast< int >(property("IPTOS")); }

    Q_PROPERTY(int IPTTL READ iPTTL)
    inline int iPTTL() const
    { return qvariant_cast< int >(property("IPTTL")); }

    Q_PROPERTY(bool IgnoreSIGPIPE READ ignoreSIGPIPE)
    inline bool ignoreSIGPIPE() const
    { return qvariant_cast< bool >(property("IgnoreSIGPIPE")); }

    Q_PROPERTY(QStringList InaccessibleDirectories READ inaccessibleDirectories)
    inline QStringList inaccessibleDirectories() const
    { return qvariant_cast< QStringList >(property("InaccessibleDirectories")); }

    Q_PROPERTY(bool KeepAlive READ keepAlive)
    inline bool keepAlive() const
    { return qvariant_cast< bool >(property("KeepAlive")); }

    Q_PROPERTY(QString KillMode READ killMode)
    inline QString killMode() const
    { return qvariant_cast< QString >(property("KillMode")); }

    Q_PROPERTY(int KillSignal READ killSignal)
    inline int killSignal() const
    { return qvariant_cast< int >(property("KillSignal")); }

    Q_PROPERTY(qulonglong LimitAS READ limitAS)
    inline qulonglong limitAS() const
    { return qvariant_cast< qulonglong >(property("LimitAS")); }

    Q_PROPERTY(qulonglong LimitCORE READ limitCORE)
    inline qulonglong limitCORE() const
    { return qvariant_cast< qulonglong >(property("LimitCORE")); }

    Q_PROPERTY(qulonglong LimitCPU READ limitCPU)
    inline qulonglong limitCPU() const
    { return qvariant_cast< qulonglong >(property("LimitCPU")); }

    Q_PROPERTY(qulonglong LimitDATA READ limitDATA)
    inline qulonglong limitDATA() const
    { return qvariant_cast< qulonglong >(property("LimitDATA")); }

    Q_PROPERTY(qulonglong LimitFSIZE READ limitFSIZE)
    inline qulonglong limitFSIZE() const
    { return qvariant_cast< qulonglong >(property("LimitFSIZE")); }

    Q_PROPERTY(qulonglong LimitLOCKS READ limitLOCKS)
    inline qulonglong limitLOCKS() const
    { return qvariant_cast< qulonglong >(property("LimitLOCKS")); }

    Q_PROPERTY(qulonglong LimitMEMLOCK READ limitMEMLOCK)
    inline qulonglong limitMEMLOCK() const
    { return qvariant_cast< qulonglong >(property("LimitMEMLOCK")); }

    Q_PROPERTY(qulonglong LimitMSGQUEUE READ limitMSGQUEUE)
    inline qulonglong limitMSGQUEUE() const
    { return qvariant_cast< qulonglong >(property("LimitMSGQUEUE")); }

    Q_PROPERTY(qulonglong LimitNICE READ limitNICE)
    inline qulonglong limitNICE() const
    { return qvariant_cast< qulonglong >(property("LimitNICE")); }

    Q_PROPERTY(qulonglong LimitNOFILE READ limitNOFILE)
    inline qulonglong limitNOFILE() const
    { return qvariant_cast< qulonglong >(property("LimitNOFILE")); }

    Q_PROPERTY(qulonglong LimitNPROC READ limitNPROC)
    inline qulonglong limitNPROC() const
    { return qvariant_cast< qulonglong >(property("LimitNPROC")); }

    Q_PROPERTY(qulonglong LimitRSS READ limitRSS)
    inline qulonglong limitRSS() const
    { return qvariant_cast< qulonglong >(property("LimitRSS")); }

    Q_PROPERTY(qulonglong LimitRTPRIO READ limitRTPRIO)
    inline qulonglong limitRTPRIO() const
    { return qvariant_cast< qulonglong >(property("LimitRTPRIO")); }

    Q_PROPERTY(qulonglong LimitRTTIME READ limitRTTIME)
    inline qulonglong limitRTTIME() const
    { return qvariant_cast< qulonglong >(property("LimitRTTIME")); }

    Q_PROPERTY(qulonglong LimitSIGPENDING READ limitSIGPENDING)
    inline qulonglong limitSIGPENDING() const
    { return qvariant_cast< qulonglong >(property("LimitSIGPENDING")); }

    Q_PROPERTY(qulonglong LimitSTACK READ limitSTACK)
    inline qulonglong limitSTACK() const
    { return qvariant_cast< qulonglong >(property("LimitSTACK")); }

    Q_PROPERTY(int Mark READ mark)
    inline int mark() const
    { return qvariant_cast< int >(property("Mark")); }

    Q_PROPERTY(uint MaxConnections READ maxConnections)
    inline uint maxConnections() const
    { return qvariant_cast< uint >(property("MaxConnections")); }

    Q_PROPERTY(qlonglong MessageQueueMaxMessages READ messageQueueMaxMessages)
    inline qlonglong messageQueueMaxMessages() const
    { return qvariant_cast< qlonglong >(property("MessageQueueMaxMessages")); }

    Q_PROPERTY(qlonglong MessageQueueMessageSize READ messageQueueMessageSize)
    inline qlonglong messageQueueMessageSize() const
    { return qvariant_cast< qlonglong >(property("MessageQueueMessageSize")); }

    Q_PROPERTY(qulonglong MountFlags READ mountFlags)
    inline qulonglong mountFlags() const
    { return qvariant_cast< qulonglong >(property("MountFlags")); }

    Q_PROPERTY(uint NAccepted READ nAccepted)
    inline uint nAccepted() const
    { return qvariant_cast< uint >(property("NAccepted")); }

    Q_PROPERTY(uint NConnections READ nConnections)
    inline uint nConnections() const
    { return qvariant_cast< uint >(property("NConnections")); }

    Q_PROPERTY(int Nice READ nice)
    inline int nice() const
    { return qvariant_cast< int >(property("Nice")); }

    Q_PROPERTY(bool NoNewPrivileges READ noNewPrivileges)
    inline bool noNewPrivileges() const
    { return qvariant_cast< bool >(property("NoNewPrivileges")); }

    Q_PROPERTY(bool NonBlocking READ nonBlocking)
    inline bool nonBlocking() const
    { return qvariant_cast< bool >(property("NonBlocking")); }

    Q_PROPERTY(int OOMScoreAdjust READ oOMScoreAdjust)
    inline int oOMScoreAdjust() const
    { return qvariant_cast< int >(property("OOMScoreAdjust")); }

    Q_PROPERTY(QString PAMName READ pAMName)
    inline QString pAMName() const
    { return qvariant_cast< QString >(property("PAMName")); }

    Q_PROPERTY(bool PassCredentials READ passCredentials)
    inline bool passCredentials() const
    { return qvariant_cast< bool >(property("PassCredentials")); }

    Q_PROPERTY(bool PassSecurity READ passSecurity)
    inline bool passSecurity() const
    { return qvariant_cast< bool >(property("PassSecurity")); }

    Q_PROPERTY(qulonglong PipeSize READ pipeSize)
    inline qulonglong pipeSize() const
    { return qvariant_cast< qulonglong >(property("PipeSize")); }

    Q_PROPERTY(int Priority READ priority)
    inline int priority() const
    { return qvariant_cast< int >(property("Priority")); }

    Q_PROPERTY(bool PrivateNetwork READ privateNetwork)
    inline bool privateNetwork() const
    { return qvariant_cast< bool >(property("PrivateNetwork")); }

    Q_PROPERTY(bool PrivateTmp READ privateTmp)
    inline bool privateTmp() const
    { return qvariant_cast< bool >(property("PrivateTmp")); }

    Q_PROPERTY(QStringList ReadOnlyDirectories READ readOnlyDirectories)
    inline QStringList readOnlyDirectories() const
    { return qvariant_cast< QStringList >(property("ReadOnlyDirectories")); }

    Q_PROPERTY(QStringList ReadWriteDirectories READ readWriteDirectories)
    inline QStringList readWriteDirectories() const
    { return qvariant_cast< QStringList >(property("ReadWriteDirectories")); }

    Q_PROPERTY(qulonglong ReceiveBuffer READ receiveBuffer)
    inline qulonglong receiveBuffer() const
    { return qvariant_cast< qulonglong >(property("ReceiveBuffer")); }

    Q_PROPERTY(QString Result READ result)
    inline QString result() const
    { return qvariant_cast< QString >(property("Result")); }

    Q_PROPERTY(QString RootDirectory READ rootDirectory)
    inline QString rootDirectory() const
    { return qvariant_cast< QString >(property("RootDirectory")); }

    Q_PROPERTY(bool SameProcessGroup READ sameProcessGroup)
    inline bool sameProcessGroup() const
    { return qvariant_cast< bool >(property("SameProcessGroup")); }

    Q_PROPERTY(int SecureBits READ secureBits)
    inline int secureBits() const
    { return qvariant_cast< int >(property("SecureBits")); }

    Q_PROPERTY(qulonglong SendBuffer READ sendBuffer)
    inline qulonglong sendBuffer() const
    { return qvariant_cast< qulonglong >(property("SendBuffer")); }

    Q_PROPERTY(bool SendSIGKILL READ sendSIGKILL)
    inline bool sendSIGKILL() const
    { return qvariant_cast< bool >(property("SendSIGKILL")); }

    Q_PROPERTY(QString SmackLabel READ smackLabel)
    inline QString smackLabel() const
    { return qvariant_cast< QString >(property("SmackLabel")); }

    Q_PROPERTY(QString SmackLabelIPIn READ smackLabelIPIn)
    inline QString smackLabelIPIn() const
    { return qvariant_cast< QString >(property("SmackLabelIPIn")); }

    Q_PROPERTY(QString SmackLabelIPOut READ smackLabelIPOut)
    inline QString smackLabelIPOut() const
    { return qvariant_cast< QString >(property("SmackLabelIPOut")); }

    Q_PROPERTY(uint SocketMode READ socketMode)
    inline uint socketMode() const
    { return qvariant_cast< uint >(property("SocketMode")); }

    Q_PROPERTY(QString StandardError READ standardError)
    inline QString standardError() const
    { return qvariant_cast< QString >(property("StandardError")); }

    Q_PROPERTY(QString StandardInput READ standardInput)
    inline QString standardInput() const
    { return qvariant_cast< QString >(property("StandardInput")); }

    Q_PROPERTY(QString StandardOutput READ standardOutput)
    inline QString standardOutput() const
    { return qvariant_cast< QString >(property("StandardOutput")); }

    Q_PROPERTY(QStringList SupplementaryGroups READ supplementaryGroups)
    inline QStringList supplementaryGroups() const
    { return qvariant_cast< QStringList >(property("SupplementaryGroups")); }

    Q_PROPERTY(QString SyslogIdentifier READ syslogIdentifier)
    inline QString syslogIdentifier() const
    { return qvariant_cast< QString >(property("SyslogIdentifier")); }

    Q_PROPERTY(bool SyslogLevelPrefix READ syslogLevelPrefix)
    inline bool syslogLevelPrefix() const
    { return qvariant_cast< bool >(property("SyslogLevelPrefix")); }

    Q_PROPERTY(int SyslogPriority READ syslogPriority)
    inline int syslogPriority() const
    { return qvariant_cast< int >(property("SyslogPriority")); }

    Q_PROPERTY(UIntList SystemCallFilter READ systemCallFilter)
    inline UIntList systemCallFilter() const
    { return qvariant_cast< UIntList >(property("SystemCallFilter")); }

    Q_PROPERTY(QString TCPWrapName READ tCPWrapName)
    inline QString tCPWrapName() const
    { return qvariant_cast< QString >(property("TCPWrapName")); }

    Q_PROPERTY(QString TTYPath READ tTYPath)
    inline QString tTYPath() const
    { return qvariant_cast< QString >(property("TTYPath")); }

    Q_PROPERTY(bool TTYReset READ tTYReset)
    inline bool tTYReset() const
    { return qvariant_cast< bool >(property("TTYReset")); }

    Q_PROPERTY(bool TTYVHangup READ tTYVHangup)
    inline bool tTYVHangup() const
    { return qvariant_cast< bool >(property("TTYVHangup")); }

    Q_PROPERTY(bool TTYVTDisallocate READ tTYVTDisallocate)
    inline bool tTYVTDisallocate() const
    { return qvariant_cast< bool >(property("TTYVTDisallocate")); }

    Q_PROPERTY(qulonglong TimeoutUSec READ timeoutUSec)
    inline qulonglong timeoutUSec() const
    { return qvariant_cast< qulonglong >(property("TimeoutUSec")); }

    Q_PROPERTY(qulonglong TimerSlackNS READ timerSlackNS)
    inline qulonglong timerSlackNS() const
    { return qvariant_cast< qulonglong >(property("TimerSlackNS")); }

    Q_PROPERTY(bool Transparent READ transparent)
    inline bool transparent() const
    { return qvariant_cast< bool >(property("Transparent")); }

    Q_PROPERTY(uint UMask READ uMask)
    inline uint uMask() const
    { return qvariant_cast< uint >(property("UMask")); }

    Q_PROPERTY(QString User READ user)
    inline QString user() const
    { return qvariant_cast< QString >(property("User")); }

    Q_PROPERTY(QString UtmpIdentifier READ utmpIdentifier)
    inline QString utmpIdentifier() const
    { return qvariant_cast< QString >(property("UtmpIdentifier")); }

    Q_PROPERTY(QString WorkingDirectory READ workingDirectory)
    inline QString workingDirectory() const
    { return qvariant_cast< QString >(property("WorkingDirectory")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QStringList> GetControlGroupAttribute(const QString &attribute)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(attribute);
        return asyncCallWithArgumentList(QLatin1String("GetControlGroupAttribute"), argumentList);
    }

    inline QDBusPendingReply<> SetControlGroup(const QString &group, const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(group) << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("SetControlGroup"), argumentList);
    }

    inline QDBusPendingReply<> SetControlGroupAttribute(const QString &attribute, const QStringList &values, const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(attribute) << QVariant::fromValue(values) << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("SetControlGroupAttribute"), argumentList);
    }

    inline QDBusPendingReply<> UnsetControlGroup(const QString &group, const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(group) << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("UnsetControlGroup"), argumentList);
    }

    inline QDBusPendingReply<> UnsetControlGroupAttribute(const QString &attribute, const QString &mode)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(attribute) << QVariant::fromValue(mode);
        return asyncCallWithArgumentList(QLatin1String("UnsetControlGroupAttribute"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

#endif
