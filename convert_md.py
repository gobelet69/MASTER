import os
import markdown
from weasyprint import HTML, CSS

# --- CONFIGURATION ---
SOURCE_DIR = './'               # Dossier source
DESTINATION_DIR = './my_pdf_export'  # Dossier de destination

# --- CSS HAUTE QUALITÉ ---
MODERN_CSS = """
    @page {
        size: A4;
        margin: 20mm;
        /* Ajoute automatiquement les numéros de page en bas à droite */
        @bottom-right {
            content: counter(page);
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, sans-serif;
            font-size: 10pt;
            color: #777;
        }
    }
    
    body { 
        font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif; 
        line-height: 1.6; 
        color: #24292e; 
        font-size: 11pt;
        text-rendering: optimizeLegibility; /* Améliore le rendu des polices */
    }

    /* 1. SAUTS DE PAGE POUR LES H1 (#) */
    h1 { 
        page-break-before: always; /* Syntaxe pour compatibilité */
        break-before: page;        /* Force une nouvelle page pour chaque # */
        border-bottom: 1px solid #eaecef; 
        padding-bottom: .3em; 
        margin-top: 24px;
        margin-bottom: 16px;
        font-weight: 600;
        line-height: 1.25;
    }
    
    /* 2. GESTION DES SAUTS DE PAGE PROPRES */
    /* Les autres titres ne doivent pas être le dernier élément d'une page */
    h2, h3, h4, h5 { 
        page-break-after: avoid; 
        break-after: avoid;
        margin-top: 24px;
        margin-bottom: 16px;
        font-weight: 600;
        line-height: 1.25;
    }
    
    h2 { border-bottom: 1px solid #eaecef; padding-bottom: .3em; }

    /* Empêche de couper un paragraphe, code, image ou tableau au milieu */
    p, pre, blockquote, table, img, ul, ol, li { 
        page-break-inside: avoid; 
        break-inside: avoid;
    }

    /* 3. DESIGN TYPE GITHUB POUR UNE MEILLEURE QUALITÉ VISUELLE */
    code { 
        background-color: rgba(27,31,35,0.05); 
        padding: 0.2em 0.4em; 
        border-radius: 3px; 
        font-family: "SFMono-Regular", Consolas, "Liberation Mono", Menlo, Courier, monospace;
        font-size: 85%;
    }
    
    pre {
        background-color: #f6f8fa;
        border-radius: 6px;
        padding: 16px;
        overflow: auto;
        border: 1px solid #e1e4e8;
    }
    
    pre code { 
        background-color: transparent; 
        padding: 0; 
        font-size: 100%;
    }

    table { border-collapse: collapse; width: 100%; margin-bottom: 16px; }
    table th, table td { border: 1px solid #dfe2e5; padding: 6px 13px; }
    table tr:nth-child(2n) { background-color: #f6f8fa; }
    
    blockquote {
        padding: 0 1em;
        color: #6a737d;
        border-left: .25em solid #dfe2e5;
        margin: 0 0 16px 0;
    }

    img { max-width: 100%; height: auto; display: block; margin: 0 auto; }
"""

def convert_md_to_pdf(src_path, dest_path):
    """Convertit un fichier Markdown en PDF de haute qualité."""
    try:
        with open(src_path, 'r', encoding='utf-8') as f:
            md_content = f.read()

        # Extensions supplémentaires pour une meilleure qualité de texte (ex: smarty pour la typographie)
        html_body = markdown.markdown(
            md_content, 
            extensions=['fenced_code', 'tables', 'sane_lists', 'nl2br', 'smarty']
        )

        html_content = f"""
        <!DOCTYPE html>
        <html>
        <head><meta charset="utf-8"></head>
        <body>
            {html_body}
        </body>
        </html>
        """

        css = CSS(string=MODERN_CSS)
        
        # Le paramètre base_url permet de s'assurer que les images locales 
        # référencées dans ton .md sont correctement trouvées et affichées.
        HTML(string=html_content, base_url=os.path.dirname(src_path)).write_pdf(
            dest_path, 
            stylesheets=[css]
        )
        print(f"✅ Converted: {os.path.basename(src_path)}")

    except Exception as e:
        print(f"❌ Error converting {src_path}:\n{e}")

def process_directory(source, destination):
    """Parcourt les dossiers en ignorant les fichiers/dossiers cachés."""
    if not os.path.exists(destination):
        os.makedirs(destination)

    for root, dirs, files in os.walk(source):
        # 1. IGNORER LES DOSSIERS CACHÉS (.git, .obsidian, etc.)
        dirs[:] = [d for d in dirs if not d.startswith('.')]

        rel_path = os.path.relpath(root, source)
        target_dir = os.path.join(destination, rel_path)

        if not os.path.exists(target_dir):
            os.makedirs(target_dir)

        for file in files:
            # 2. IGNORER LES FICHIERS CACHÉS (.DS_Store, etc.)
            if file.startswith('.'):
                continue
                
            if file.lower().endswith('.md'):
                src_file = os.path.join(root, file)
                base_name = os.path.splitext(file)[0]
                dest_file = os.path.join(target_dir, base_name + '.pdf')
                
                convert_md_to_pdf(src_file, dest_file)

if __name__ == "__main__":
    print(f"Starting conversion from '{SOURCE_DIR}' to '{DESTINATION_DIR}'...")
    process_directory(SOURCE_DIR, DESTINATION_DIR)
    print("Done!")