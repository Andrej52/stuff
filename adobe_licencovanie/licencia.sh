#!/bin/bash

#path to licence kit
local_root="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
parth_to_licnece_kit=$local_root/"adobe-licensing-toolkit/win64"

detect_windows()
{
    # Get the operating system name
    os_name=$(uname)
    if [[ "$os_name" == "Darwin" ]]; then
        return 1
    elif [[ "$os_name" == "MINGW64_NT"* || "$os_name" == "MSYS_NT"* || "$os_name" == "CYGWIN_NT"* ]]; then
        return 2
    elif [[ "$os_name" == "Linux" || "$os_name" == *"Microsoft"* ]]; then
        return 3
    else
        return 0
    fi
}

show_help()
{
    echo "-informations  zobrazí informácie o licenciach"
    echo "-package-detail zobrazí informácie o nainštalovanom packagi"
    echo "-deactive-all deaktivuje všetky licencie packagu"
}

if [ $# -eq 0 ]; then
    echo "nebol najdeny prikaz napiste -help"
    exit 1
fi
case "$1" in
    '-informacie')
        case $(detect_windows) in
            1)  # macOS
                echo "MacOS detected"
                "sudo /$path_to_licence_kit/adobe-licensing-toolkit -l"
                ;;
            2)  # Windows
                echo "Windows detected"
                "$path_to_licence_kit/adobe-licensing-toolkit.exe -l"
                ;;
            3)  #LINUX
                echo "Linux or WSL detected"
                "sudo /$path_to_licence_kit/adobe-licensing-toolkit -l"
                ;;
            *)  # Unknown OS
                echo "Unknown OS. Cannot proceed."
                ;;
        esac
    ;;
    '-package-detail') 
        case $(detect_windows) in
                1|3)  # macOS
                    "sudo ./$path_to_licence_kit/adobe-licensing-toolkit -d"
                    ;;
                2)  # Windows
                    "$path_to_licence_kit/adobe-licensing-toolkit.exe -d"
                    ;;
                *)  # Unknown OS
                    echo "Unknown OS. Cannot proceed."
                     echo "$os_name"
                    exit 1
                    ;;
            esac
    ;;
    '-deactive-all')
    echo "Skutočne chcete deaktivovať všetky licencie? (y/n)"
    read answer
    case "$answer" in
        [Yy]*)
            echo "Deaktivácia všetkých služieb..."
            case $(detect_windows) in
                1|3)  # macOS or Linux/WSL
                    sudo "$path_to_licence_kit/adobe-licensing-toolkit" -t
                    ;;
                2)  # Windows
                    "$path_to_licence_kit/adobe-licensing-toolkit.exe" -t
                    ;;
                *)
                    echo "Unknown OS. Cannot proceed."
                    echo "$(uname)"  # Vypíše názov neznámeho operačného systému
                    exit 1
                    ;;
            esac
            ;;
        [Nn]*)
            echo "Operácia zrušená."
            ;;
        *)
            echo "Neplatná odpoveď. Operácia zrušená."
            ;;
    esac
    ;;
    '-help')
        show_help
    ;;
    *) echo default
        echo "neplatný príkaz pouzite príkaz -help"
    ;;
esac