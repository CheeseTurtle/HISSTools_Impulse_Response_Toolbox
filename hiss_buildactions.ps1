param(
    [Switch]$PreBuild=$false,
    [Switch]$PostBuild=$false,
    [Switch]$NoKill=$false,
    [Switch]$UpToDate=$false
)
$proc = $null;

$proc = (Get-Process -Name Max -ErrorAction Ignore | Where-Object -Property Path -eq "C:\Program Files\Cycling '74\Max 8\Max.exe");

if($proc) {
    if(-not $proc.Responding) { 
        if($NoKill) { return; } else { $proc.Kill(); }
    }
}
if ($PostBuild) {
    if($proc -and -not $proc.HasExited) { return; }
    Start-Process -FilePath "C:\Program Files\Cycling '74\Max 8\Max.exe"
} elseif($PreBuild -and $proc) {
    if($proc.HasExited) { return; }
    
    $proc.Close();
    if($proc -and $proc.Id -and -not ($proc.HasExited)) { 
        $proc = Stop-Process -InputObject $proc -ErrorAction Ignore -PassThru
    };
    $proc = (Get-Process -Name Max -ErrorAction Ignore | Where-Object -Property Path -eq "C:\Program Files\Cycling '74\Max 8\Max.exe");
    if($proc -and $proc.Id -and -not ($proc.HasExited)) {
        Wait-Process -Id $proc.Id;
    };
}